#pragma once

#include "../forward_declarations.h"

static PyMethodDef humat3x2_methods[] = {
	{ "__copy__", (PyCFunction)generic_copy, METH_NOARGS, "Create a copy of this instance"},
	{ "__deepcopy__", (PyCFunction)generic_deepcopy, METH_O, "Create a (deep)copy of this instance"},
	{"length", (PyCFunction)mat_length<3>, METH_NOARGS, "returns the length of glm::umat3x2"},
	{ "to_list", (PyCFunction)mat_to_list<3, 2, glm::u32>, METH_NOARGS, "Return the components of this matrix as a nested list"},
	{ "to_tuple", (PyCFunction)mat_to_tuple<3, 2, glm::u32>, METH_NOARGS, "Return the components of this matrix as a nested tuple"},
	{ NULL }
};
static PyBufferProcs humat3x2BufferMethods = {
	(getbufferproc)mat_getbuffer<3, 2, glm::u32>,
	(releasebufferproc)mat_releasebuffer,
};
static PySequenceMethods humat3x2SeqMethods = {
	(lenfunc)mat_len<3>, // sq_length
	0, // sq_concat
	0, // sq_repeat
	0, // sq_item
	0,
	0, // sq_ass_item
	0,
	(objobjproc)mat_contains<3, 2, glm::u32>, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};
static PyMappingMethods humat3x2MapMethods = {
	(lenfunc)mat_len<3>, // mp_length
	(binaryfunc)mat3x2_mp_item<glm::u32>, // mp_subscript
	(objobjargproc)mat3x2_mp_ass_item<glm::u32>, // mp_ass_subscript
};
static PyNumberMethods humat3x2NumMethods = {
	(binaryfunc)mat_add<3, 2, glm::u32>, //nb_add
	(binaryfunc)mat_sub<3, 2, glm::u32>, //nb_subtract
	(binaryfunc)mat_mul<3, 2, glm::u32>, //nb_multiply
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	0, //nb_negative
	(unaryfunc)mat_pos<3, 2, glm::u32>, //nb_positive
	0, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_glm::u32
	(binaryfunc)mat_iadd<3, 2, glm::u32>, //nb_inplace_add
	(binaryfunc)mat_isub<3, 2, glm::u32>, //nb_inplace_subtract
	(binaryfunc)mat_imul<3, 2, glm::u32>, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or
	0, //nb_floor_divide
	(binaryfunc)mat_div<3, 2, glm::u32>,
	0, //nb_inplace_floor_divide
	(binaryfunc)mat_idiv<3, 2, glm::u32>, //nb_inplace_true_divide
	0, //nb_index
};
static PyTypeObject humat3x2Type = {
	PyObject_HEAD_INIT(NULL)
	"glm.umat3x2",             /* tp_name */
	sizeof(mat<3, 2, glm::u32>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)mat_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)mat3x2_repr<glm::u32>,                         /* tp_repr */
	&humat3x2NumMethods,             /* tp_as_number */
	&humat3x2SeqMethods,                         /* tp_as_sequence */
	&humat3x2MapMethods,                         /* tp_as_mapping */
	(hashfunc)mat_hash<3, 2, glm::u32>,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)mat3x2_str<glm::u32>,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	&humat3x2BufferMethods,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"umat3x2( <umat3x2 compatible type(s)> )\n3 columns of 2 components matrix of unsigned integer numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)mat_richcompare<3, 2, glm::u32>,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)mat_geniter<3, 2, glm::u32>,                         /* tp_iter */
	0,                         /* tp_iternext */
	humat3x2_methods,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)mat3x2_init<glm::u32>,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)mat_new<3, 2, glm::u32>,                 /* tp_new */
};
static PyTypeObject humat3x2IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"umat3x2Iter",             /* tp_name */
	sizeof(matIter<3, 2, glm::u32>),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)matIter_dealloc<3, 2, glm::u32>, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"umat3x2 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)matIter_next<3, 2, glm::u32>,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)matIter_new<3, 2, glm::u32>,                 /* tp_new */
};