const Collision mtc_platspin_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(14),
	COL_VERTEX(97, 66, 168),
	COL_VERTEX(194, 66, 0),
	COL_VERTEX(0, 66, 0),
	COL_VERTEX(-97, 66, 168),
	COL_VERTEX(-194, 66, 0),
	COL_VERTEX(-97, 66, -168),
	COL_VERTEX(-297, -15, 0),
	COL_VERTEX(-149, -15, -257),
	COL_VERTEX(97, 66, -168),
	COL_VERTEX(148, -15, -257),
	COL_VERTEX(297, -15, 0),
	COL_VERTEX(148, -15, 257),
	COL_VERTEX(-149, -15, 257),
	COL_VERTEX(0, -366, 0),
	COL_TRI_INIT(SURFACE_NOT_SLIPPERY, 24),
	COL_TRI(0, 1, 2),
	COL_TRI(3, 0, 2),
	COL_TRI(3, 2, 4),
	COL_TRI(5, 4, 2),
	COL_TRI(6, 4, 5),
	COL_TRI(6, 5, 7),
	COL_TRI(7, 5, 8),
	COL_TRI(7, 8, 9),
	COL_TRI(8, 5, 2),
	COL_TRI(8, 2, 1),
	COL_TRI(8, 1, 10),
	COL_TRI(8, 10, 9),
	COL_TRI(0, 11, 10),
	COL_TRI(0, 10, 1),
	COL_TRI(12, 11, 0),
	COL_TRI(12, 0, 3),
	COL_TRI(6, 12, 3),
	COL_TRI(6, 3, 4),
	COL_TRI(6, 13, 12),
	COL_TRI(7, 13, 6),
	COL_TRI(13, 7, 9),
	COL_TRI(13, 9, 10),
	COL_TRI(13, 10, 11),
	COL_TRI(13, 11, 12),
	COL_TRI_STOP(),
	COL_END()
};