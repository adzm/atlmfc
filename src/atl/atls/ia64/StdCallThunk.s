// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the	
// Active Template Library product.

	.global	_StdCallThunkProcProc
	.proc	_StdCallThunkProcProc
	.global _StdCallThunkProc
	.align	32

_StdCallThunkProcProc:
_StdCallThunkProc:
	// On entry, gp is actually a pointer to the m_pFunc member of 
	// the _stdcallthunk struct
	mov		r14=gp
	ld8		r15=[r14],8		// r15 = m_pFunc, r14 = &m_pThis
	ld8		r16=[r15],8		// r16 = m_pFunc->pfn, r15 = &m_pFunc->gp
	ld8		gp=[r15]		// gp = m_pFunc->gp
	ld8		r32=[r14]		// r32 = m_pThis
	mov		b6=r16			// b6 = m_pFunc->pfn
	br.cond.sptk.many	b6	// Jump to the real proc
	.endp	_StdCallThunkProcProc
	
