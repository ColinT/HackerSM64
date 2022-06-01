const Collision hf_bridge1_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(24),
	COL_VERTEX(-1565, 5825, 914), // -
	COL_VERTEX(-1959, 5842, 914), // -
	COL_VERTEX(-1959, 5842, 1455), // -
	COL_VERTEX(-1565, 5825, 1455), // -
	COL_VERTEX(-2398, 5747, 914),
	COL_VERTEX(-2398, 5747, 1455),
	COL_VERTEX(-2837, 5358, 914),
	COL_VERTEX(-2837, 5358, 1455),
	COL_VERTEX(-2837, 5064, 1455),
	COL_VERTEX(-2837, 5064, 914),
	COL_VERTEX(-1172, 5808, 914), // <-
	COL_VERTEX(-1172, 5808, 1455), // <-
	COL_VERTEX(1484, 4165, 914),
	COL_VERTEX(695, 5220, 914),
	COL_VERTEX(695, 5220, 1455),
	COL_VERTEX(1484, 4165, 1455),
	COL_VERTEX(120, 5602, 914),
	COL_VERTEX(120, 5602, 1455),
	COL_VERTEX(-385, 5774, 914),
	COL_VERTEX(-385, 5774, 1455),
	COL_VERTEX(-778, 5791, 914),
	COL_VERTEX(-1164, 5808, 914), // <-
	COL_VERTEX(-1164, 5808, 1455), // <-
	COL_VERTEX(-778, 5791, 1455),
	COL_TRI_INIT(SURFACE_NOT_SLIPPERY, 20),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(1, 4, 5),
	COL_TRI(1, 5, 2),
	COL_TRI(4, 6, 7),
	COL_TRI(4, 7, 5),
	COL_TRI(8, 7, 6),
	COL_TRI(8, 6, 9),
	COL_TRI(10, 0, 3),
	COL_TRI(10, 3, 11),
	COL_TRI(12, 13, 14),
	COL_TRI(12, 14, 15),
	COL_TRI(13, 16, 17),
	COL_TRI(13, 17, 14),
	COL_TRI(16, 18, 19),
	COL_TRI(16, 19, 17),
	COL_TRI(20, 21, 22),
	COL_TRI(20, 22, 23),
	COL_TRI(18, 20, 23),
	COL_TRI(18, 23, 19),
	COL_TRI_STOP(),
	COL_END()
};