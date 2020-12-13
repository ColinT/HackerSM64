#include <ultra64.h>
#include "config.h"
#include "mtx.h"

int myScale = 1;
int myDegrees = 0;
uObjMtx final_mtx, rot_mtx;
int s2d_red = 255, s2d_green = 255, s2d_blue = 255, s2d_alpha = 255;

static Gfx s2d_init_dl[] = {
	gsDPPipeSync(),
	gsDPSetTexturePersp(G_TP_NONE),
	gsDPSetTextureLOD(G_TL_TILE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsDPSetTextureConvert(G_TC_FILT),
	gsDPSetAlphaCompare(G_AC_THRESHOLD),
	gsDPSetBlendColor(0, 0, 0, 0x01),

    // IA8
	gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT,
                       0, 0, 0, TEXEL0,
                       0, 0, 0, ENVIRONMENT,
                       0, 0, 0, TEXEL0),

	gsSPEndDisplayList(),
};

void setup_font(int idx) {
	gDPPipeSync(gdl_head++);
	gDPSetTextureFilter(gdl_head++, G_TF_POINT);
	gSPDisplayList(gdl_head++, s2d_init_dl);
    gDPSetEnvColor(gdl_head++, s2d_red, s2d_green, s2d_blue, s2d_alpha);
	gDPSetCycleType(gdl_head++, G_CYC_1CYCLE);
	gDPSetRenderMode(gdl_head++, G_RM_XLU_SPRITE, G_RM_XLU_SPRITE2);
	gSPObjRenderMode(gdl_head++, G_OBJRM_XLU | G_OBJRM_BILERP);
	gSPObjLoadTxtr(gdl_head++, &s2d_tex[idx]);
}

void draw_rect(int ulx, int uly, int drx, int dry, u32 color) {
    gDPPipeSync(gdl_head++);
    gDPSetRenderMode(gdl_head++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetCycleType(gdl_head++,G_CYC_FILL);
    gDPSetFillColor(gdl_head++, color);
    gDPFillRectangle(gdl_head++, ulx, uly, drx, dry);
    gDPPipeSync(gdl_head++);
    gDPSetCycleType(gdl_head++, G_CYC_1CYCLE);
}

// Original Mtx Pipeline
// Distorts when rotating, but is faster
void mtx_pipeline(uObjMtx *m, int x, int y) {
	// init
	mat2_ident(m, 1);
	mat2_ident(&rot_mtx, 1);

	// create rot matrix
	mat2_rotate(&rot_mtx, (myDegrees) * (M_PI / 180.0f));
	// scale m
	mat2_scale(m, myScale);
	mat2_dst_mul(m,m,  &rot_mtx);
	mat2_translate(m, x, y);

	gSPObjMatrix(gdl_head++, m);
}

// New matrix pipeline
// Works with both rotation and scale,
// but is slow due to more float operations being performed
void mtx_pipeline2(uObjMtx *m, int x, int y) {
	// init
	Mat4 tmp, rot, scal, translate;
	guMtxIdentF(tmp);
	guScaleF(scal, myScale, myScale, 0);
	guRotateF(rot, (f32) myDegrees, 0, 0, 1.0f);
	guTranslateF(translate, x, y, 0);

	mtxf_mul(tmp, tmp, scal);
	mtxf_mul(tmp, tmp, rot);
	mtxf_mul(tmp, tmp, translate);

	gu_to_gs2dex(m, tmp);

    if (myDegrees != 0) {
        mat2_translate_vec(m, -(myDegrees) * M_DTOR, myScale);
    }

	gSPObjMatrix(gdl_head++, m);
}

void draw_s2d_glyph(char c, int x, int y, uObjMtx *mt) {
	setup_font(c);

	// mtx_pipeline(mt, x, y);
    mtx_pipeline2(mt, x, y);

	gSPObjSprite(gdl_head++, &s2d_font);
}


