static PyObject* functor1(double(*Func)(double x), PyObject * arg) {
	void* o = NULL;
	char vecType = unpack_ivec(arg, &o);

	if (vecType == GLM_TVEC2) {
		return pack_tvec2(Func(((ivec2*)o)->x), Func(((ivec2*)o)->y));
	}
	if (vecType == GLM_TVEC3) {
		return pack_tvec3(Func(((ivec3*)o)->x), Func(((ivec3*)o)->y), Func(((ivec3*)o)->z));
	}
	if (vecType == GLM_TVEC4) {
		return pack_tvec4(Func(((ivec4*)o)->x), Func(((ivec4*)o)->y), Func(((ivec4*)o)->z), Func(((ivec4*)o)->w));
	}
	return NULL;
}

static PyObject* functor2(double(*Func)(double x, double y), PyObject * arg1, PyObject * arg2) {
	void* o = NULL;
	char vecType = unpack_ivec(arg1, &o);

	if (vecType == GLM_TVEC2) {
		ivec2* o2 = unpack_ivec2(arg2);
		if (o2 == NULL) {
			return NULL;
		}
		return pack_tvec2(Func(((ivec2*)o)->x, ((ivec2*)o2)->x), Func(((ivec2*)o)->y, ((ivec2*)o2)->y));
	}
	if (vecType == GLM_TVEC3) {
		ivec3* o2 = unpack_ivec3(arg2);
		if (o2 == NULL) {
			return NULL;
		}
		return pack_tvec3(Func(((ivec3*)o)->x, ((ivec3*)o2)->x), Func(((ivec3*)o)->y, ((ivec3*)o2)->y), Func(((ivec3*)o)->z, ((ivec3*)o2)->z));
	}
	if (vecType == GLM_TVEC4) {
		ivec4* o2 = unpack_ivec4(arg2);
		if (o2 == NULL) {
			return NULL;
		}
		return pack_tvec4(Func(((ivec4*)o)->x, ((ivec4*)o2)->x), Func(((ivec4*)o)->y, ((ivec4*)o2)->y), Func(((ivec4*)o)->z, ((ivec4*)o2)->z), Func(((ivec4*)o)->w, ((ivec4*)o2)->w));
	}
	return NULL;
}

static PyObject* functor2_vec_sca(double(*Func)(double x, double y), PyObject * arg1, double arg2) {
	void* o = NULL;
	char vecType = unpack_ivec(arg1, &o);

	if (vecType == GLM_TVEC2) {
		return pack_tvec2(Func(((ivec2*)o)->x, arg2), Func(((ivec2*)o)->y, arg2));
	}
	if (vecType == GLM_TVEC3) {
		return pack_tvec3(Func(((ivec3*)o)->x, arg2), Func(((ivec3*)o)->y, arg2), Func(((ivec3*)o)->z, arg2));
	}
	if (vecType == GLM_TVEC4) {
		return pack_tvec4(Func(((ivec4*)o)->x, arg2), Func(((ivec4*)o)->y, arg2), Func(((ivec4*)o)->z, arg2), Func(((ivec4*)o)->w, arg2));
	}
	return NULL;
}