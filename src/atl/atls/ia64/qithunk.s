// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the	
// Active Template Library product.

	.global ?f3@_QIThunk@ATL@@UEAAJXZ
	.proc	?f3@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f3@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=3*8,r14	// r14 = &m_pUnk->vtbl[3] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[3]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[3].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[3].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f3@_QIThunk@ATL@@UEAAJXZ


	.global ?f4@_QIThunk@ATL@@UEAAJXZ
	.proc	?f4@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f4@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=4*8,r14	// r14 = &m_pUnk->vtbl[4] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[4]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[4].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[4].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f4@_QIThunk@ATL@@UEAAJXZ


	.global ?f5@_QIThunk@ATL@@UEAAJXZ
	.proc	?f5@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f5@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=5*8,r14	// r14 = &m_pUnk->vtbl[5] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[5]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[5].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[5].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f5@_QIThunk@ATL@@UEAAJXZ


	.global ?f6@_QIThunk@ATL@@UEAAJXZ
	.proc	?f6@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f6@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=6*8,r14	// r14 = &m_pUnk->vtbl[6] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[6]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[6].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[6].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f6@_QIThunk@ATL@@UEAAJXZ


	.global ?f7@_QIThunk@ATL@@UEAAJXZ
	.proc	?f7@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f7@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=7*8,r14	// r14 = &m_pUnk->vtbl[7] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[7]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[7].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[7].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f7@_QIThunk@ATL@@UEAAJXZ


	.global ?f8@_QIThunk@ATL@@UEAAJXZ
	.proc	?f8@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f8@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=8*8,r14	// r14 = &m_pUnk->vtbl[8] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[8]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[8].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[8].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f8@_QIThunk@ATL@@UEAAJXZ


	.global ?f9@_QIThunk@ATL@@UEAAJXZ
	.proc	?f9@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f9@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=9*8,r14	// r14 = &m_pUnk->vtbl[9] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[9]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[9].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[9].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f9@_QIThunk@ATL@@UEAAJXZ


	.global ?f10@_QIThunk@ATL@@UEAAJXZ
	.proc	?f10@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f10@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=10*8,r14	// r14 = &m_pUnk->vtbl[10] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[10]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[10].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[10].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f10@_QIThunk@ATL@@UEAAJXZ


	.global ?f11@_QIThunk@ATL@@UEAAJXZ
	.proc	?f11@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f11@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=11*8,r14	// r14 = &m_pUnk->vtbl[11] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[11]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[11].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[11].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f11@_QIThunk@ATL@@UEAAJXZ


	.global ?f12@_QIThunk@ATL@@UEAAJXZ
	.proc	?f12@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f12@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=12*8,r14	// r14 = &m_pUnk->vtbl[12] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[12]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[12].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[12].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f12@_QIThunk@ATL@@UEAAJXZ


	.global ?f13@_QIThunk@ATL@@UEAAJXZ
	.proc	?f13@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f13@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=13*8,r14	// r14 = &m_pUnk->vtbl[13] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[13]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[13].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[13].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f13@_QIThunk@ATL@@UEAAJXZ


	.global ?f14@_QIThunk@ATL@@UEAAJXZ
	.proc	?f14@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f14@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=14*8,r14	// r14 = &m_pUnk->vtbl[14] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[14]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[14].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[14].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f14@_QIThunk@ATL@@UEAAJXZ


	.global ?f15@_QIThunk@ATL@@UEAAJXZ
	.proc	?f15@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f15@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=15*8,r14	// r14 = &m_pUnk->vtbl[15] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[15]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[15].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[15].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f15@_QIThunk@ATL@@UEAAJXZ


	.global ?f16@_QIThunk@ATL@@UEAAJXZ
	.proc	?f16@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f16@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=16*8,r14	// r14 = &m_pUnk->vtbl[16] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[16]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[16].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[16].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f16@_QIThunk@ATL@@UEAAJXZ


	.global ?f17@_QIThunk@ATL@@UEAAJXZ
	.proc	?f17@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f17@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=17*8,r14	// r14 = &m_pUnk->vtbl[17] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[17]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[17].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[17].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f17@_QIThunk@ATL@@UEAAJXZ


	.global ?f18@_QIThunk@ATL@@UEAAJXZ
	.proc	?f18@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f18@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=18*8,r14	// r14 = &m_pUnk->vtbl[18] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[18]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[18].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[18].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f18@_QIThunk@ATL@@UEAAJXZ


	.global ?f19@_QIThunk@ATL@@UEAAJXZ
	.proc	?f19@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f19@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=19*8,r14	// r14 = &m_pUnk->vtbl[19] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[19]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[19].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[19].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f19@_QIThunk@ATL@@UEAAJXZ


	.global ?f20@_QIThunk@ATL@@UEAAJXZ
	.proc	?f20@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f20@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=20*8,r14	// r14 = &m_pUnk->vtbl[20] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[20]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[20].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[20].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f20@_QIThunk@ATL@@UEAAJXZ


	.global ?f21@_QIThunk@ATL@@UEAAJXZ
	.proc	?f21@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f21@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=21*8,r14	// r14 = &m_pUnk->vtbl[21] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[21]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[21].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[21].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f21@_QIThunk@ATL@@UEAAJXZ


	.global ?f22@_QIThunk@ATL@@UEAAJXZ
	.proc	?f22@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f22@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=22*8,r14	// r14 = &m_pUnk->vtbl[22] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[22]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[22].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[22].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f22@_QIThunk@ATL@@UEAAJXZ


	.global ?f23@_QIThunk@ATL@@UEAAJXZ
	.proc	?f23@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f23@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=23*8,r14	// r14 = &m_pUnk->vtbl[23] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[23]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[23].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[23].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f23@_QIThunk@ATL@@UEAAJXZ


	.global ?f24@_QIThunk@ATL@@UEAAJXZ
	.proc	?f24@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f24@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=24*8,r14	// r14 = &m_pUnk->vtbl[24] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[24]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[24].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[24].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f24@_QIThunk@ATL@@UEAAJXZ


	.global ?f25@_QIThunk@ATL@@UEAAJXZ
	.proc	?f25@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f25@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=25*8,r14	// r14 = &m_pUnk->vtbl[25] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[25]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[25].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[25].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f25@_QIThunk@ATL@@UEAAJXZ


	.global ?f26@_QIThunk@ATL@@UEAAJXZ
	.proc	?f26@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f26@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=26*8,r14	// r14 = &m_pUnk->vtbl[26] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[26]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[26].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[26].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f26@_QIThunk@ATL@@UEAAJXZ


	.global ?f27@_QIThunk@ATL@@UEAAJXZ
	.proc	?f27@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f27@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=27*8,r14	// r14 = &m_pUnk->vtbl[27] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[27]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[27].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[27].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f27@_QIThunk@ATL@@UEAAJXZ


	.global ?f28@_QIThunk@ATL@@UEAAJXZ
	.proc	?f28@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f28@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=28*8,r14	// r14 = &m_pUnk->vtbl[28] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[28]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[28].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[28].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f28@_QIThunk@ATL@@UEAAJXZ


	.global ?f29@_QIThunk@ATL@@UEAAJXZ
	.proc	?f29@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f29@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=29*8,r14	// r14 = &m_pUnk->vtbl[29] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[29]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[29].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[29].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f29@_QIThunk@ATL@@UEAAJXZ


	.global ?f30@_QIThunk@ATL@@UEAAJXZ
	.proc	?f30@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f30@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=30*8,r14	// r14 = &m_pUnk->vtbl[30] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[30]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[30].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[30].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f30@_QIThunk@ATL@@UEAAJXZ


	.global ?f31@_QIThunk@ATL@@UEAAJXZ
	.proc	?f31@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f31@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=31*8,r14	// r14 = &m_pUnk->vtbl[31] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[31]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[31].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[31].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f31@_QIThunk@ATL@@UEAAJXZ


	.global ?f32@_QIThunk@ATL@@UEAAJXZ
	.proc	?f32@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f32@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=32*8,r14	// r14 = &m_pUnk->vtbl[32] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[32]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[32].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[32].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f32@_QIThunk@ATL@@UEAAJXZ


	.global ?f33@_QIThunk@ATL@@UEAAJXZ
	.proc	?f33@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f33@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=33*8,r14	// r14 = &m_pUnk->vtbl[33] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[33]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[33].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[33].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f33@_QIThunk@ATL@@UEAAJXZ


	.global ?f34@_QIThunk@ATL@@UEAAJXZ
	.proc	?f34@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f34@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=34*8,r14	// r14 = &m_pUnk->vtbl[34] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[34]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[34].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[34].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f34@_QIThunk@ATL@@UEAAJXZ


	.global ?f35@_QIThunk@ATL@@UEAAJXZ
	.proc	?f35@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f35@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=35*8,r14	// r14 = &m_pUnk->vtbl[35] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[35]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[35].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[35].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f35@_QIThunk@ATL@@UEAAJXZ


	.global ?f36@_QIThunk@ATL@@UEAAJXZ
	.proc	?f36@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f36@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=36*8,r14	// r14 = &m_pUnk->vtbl[36] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[36]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[36].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[36].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f36@_QIThunk@ATL@@UEAAJXZ


	.global ?f37@_QIThunk@ATL@@UEAAJXZ
	.proc	?f37@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f37@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=37*8,r14	// r14 = &m_pUnk->vtbl[37] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[37]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[37].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[37].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f37@_QIThunk@ATL@@UEAAJXZ


	.global ?f38@_QIThunk@ATL@@UEAAJXZ
	.proc	?f38@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f38@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=38*8,r14	// r14 = &m_pUnk->vtbl[38] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[38]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[38].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[38].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f38@_QIThunk@ATL@@UEAAJXZ


	.global ?f39@_QIThunk@ATL@@UEAAJXZ
	.proc	?f39@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f39@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=39*8,r14	// r14 = &m_pUnk->vtbl[39] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[39]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[39].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[39].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f39@_QIThunk@ATL@@UEAAJXZ


	.global ?f40@_QIThunk@ATL@@UEAAJXZ
	.proc	?f40@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f40@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=40*8,r14	// r14 = &m_pUnk->vtbl[40] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[40]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[40].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[40].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f40@_QIThunk@ATL@@UEAAJXZ


	.global ?f41@_QIThunk@ATL@@UEAAJXZ
	.proc	?f41@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f41@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=41*8,r14	// r14 = &m_pUnk->vtbl[41] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[41]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[41].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[41].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f41@_QIThunk@ATL@@UEAAJXZ


	.global ?f42@_QIThunk@ATL@@UEAAJXZ
	.proc	?f42@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f42@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=42*8,r14	// r14 = &m_pUnk->vtbl[42] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[42]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[42].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[42].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f42@_QIThunk@ATL@@UEAAJXZ


	.global ?f43@_QIThunk@ATL@@UEAAJXZ
	.proc	?f43@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f43@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=43*8,r14	// r14 = &m_pUnk->vtbl[43] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[43]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[43].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[43].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f43@_QIThunk@ATL@@UEAAJXZ


	.global ?f44@_QIThunk@ATL@@UEAAJXZ
	.proc	?f44@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f44@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=44*8,r14	// r14 = &m_pUnk->vtbl[44] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[44]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[44].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[44].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f44@_QIThunk@ATL@@UEAAJXZ


	.global ?f45@_QIThunk@ATL@@UEAAJXZ
	.proc	?f45@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f45@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=45*8,r14	// r14 = &m_pUnk->vtbl[45] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[45]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[45].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[45].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f45@_QIThunk@ATL@@UEAAJXZ


	.global ?f46@_QIThunk@ATL@@UEAAJXZ
	.proc	?f46@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f46@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=46*8,r14	// r14 = &m_pUnk->vtbl[46] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[46]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[46].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[46].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f46@_QIThunk@ATL@@UEAAJXZ


	.global ?f47@_QIThunk@ATL@@UEAAJXZ
	.proc	?f47@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f47@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=47*8,r14	// r14 = &m_pUnk->vtbl[47] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[47]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[47].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[47].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f47@_QIThunk@ATL@@UEAAJXZ


	.global ?f48@_QIThunk@ATL@@UEAAJXZ
	.proc	?f48@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f48@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=48*8,r14	// r14 = &m_pUnk->vtbl[48] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[48]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[48].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[48].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f48@_QIThunk@ATL@@UEAAJXZ


	.global ?f49@_QIThunk@ATL@@UEAAJXZ
	.proc	?f49@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f49@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=49*8,r14	// r14 = &m_pUnk->vtbl[49] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[49]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[49].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[49].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f49@_QIThunk@ATL@@UEAAJXZ


	.global ?f50@_QIThunk@ATL@@UEAAJXZ
	.proc	?f50@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f50@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=50*8,r14	// r14 = &m_pUnk->vtbl[50] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[50]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[50].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[50].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f50@_QIThunk@ATL@@UEAAJXZ


	.global ?f51@_QIThunk@ATL@@UEAAJXZ
	.proc	?f51@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f51@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=51*8,r14	// r14 = &m_pUnk->vtbl[51] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[51]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[51].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[51].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f51@_QIThunk@ATL@@UEAAJXZ


	.global ?f52@_QIThunk@ATL@@UEAAJXZ
	.proc	?f52@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f52@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=52*8,r14	// r14 = &m_pUnk->vtbl[52] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[52]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[52].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[52].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f52@_QIThunk@ATL@@UEAAJXZ


	.global ?f53@_QIThunk@ATL@@UEAAJXZ
	.proc	?f53@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f53@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=53*8,r14	// r14 = &m_pUnk->vtbl[53] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[53]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[53].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[53].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f53@_QIThunk@ATL@@UEAAJXZ


	.global ?f54@_QIThunk@ATL@@UEAAJXZ
	.proc	?f54@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f54@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=54*8,r14	// r14 = &m_pUnk->vtbl[54] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[54]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[54].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[54].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f54@_QIThunk@ATL@@UEAAJXZ


	.global ?f55@_QIThunk@ATL@@UEAAJXZ
	.proc	?f55@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f55@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=55*8,r14	// r14 = &m_pUnk->vtbl[55] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[55]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[55].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[55].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f55@_QIThunk@ATL@@UEAAJXZ


	.global ?f56@_QIThunk@ATL@@UEAAJXZ
	.proc	?f56@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f56@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=56*8,r14	// r14 = &m_pUnk->vtbl[56] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[56]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[56].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[56].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f56@_QIThunk@ATL@@UEAAJXZ


	.global ?f57@_QIThunk@ATL@@UEAAJXZ
	.proc	?f57@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f57@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=57*8,r14	// r14 = &m_pUnk->vtbl[57] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[57]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[57].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[57].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f57@_QIThunk@ATL@@UEAAJXZ


	.global ?f58@_QIThunk@ATL@@UEAAJXZ
	.proc	?f58@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f58@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=58*8,r14	// r14 = &m_pUnk->vtbl[58] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[58]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[58].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[58].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f58@_QIThunk@ATL@@UEAAJXZ


	.global ?f59@_QIThunk@ATL@@UEAAJXZ
	.proc	?f59@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f59@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=59*8,r14	// r14 = &m_pUnk->vtbl[59] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[59]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[59].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[59].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f59@_QIThunk@ATL@@UEAAJXZ


	.global ?f60@_QIThunk@ATL@@UEAAJXZ
	.proc	?f60@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f60@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=60*8,r14	// r14 = &m_pUnk->vtbl[60] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[60]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[60].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[60].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f60@_QIThunk@ATL@@UEAAJXZ


	.global ?f61@_QIThunk@ATL@@UEAAJXZ
	.proc	?f61@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f61@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=61*8,r14	// r14 = &m_pUnk->vtbl[61] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[61]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[61].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[61].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f61@_QIThunk@ATL@@UEAAJXZ


	.global ?f62@_QIThunk@ATL@@UEAAJXZ
	.proc	?f62@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f62@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=62*8,r14	// r14 = &m_pUnk->vtbl[62] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[62]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[62].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[62].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f62@_QIThunk@ATL@@UEAAJXZ


	.global ?f63@_QIThunk@ATL@@UEAAJXZ
	.proc	?f63@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f63@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=63*8,r14	// r14 = &m_pUnk->vtbl[63] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[63]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[63].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[63].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f63@_QIThunk@ATL@@UEAAJXZ


	.global ?f64@_QIThunk@ATL@@UEAAJXZ
	.proc	?f64@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f64@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=64*8,r14	// r14 = &m_pUnk->vtbl[64] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[64]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[64].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[64].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f64@_QIThunk@ATL@@UEAAJXZ


	.global ?f65@_QIThunk@ATL@@UEAAJXZ
	.proc	?f65@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f65@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=65*8,r14	// r14 = &m_pUnk->vtbl[65] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[65]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[65].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[65].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f65@_QIThunk@ATL@@UEAAJXZ


	.global ?f66@_QIThunk@ATL@@UEAAJXZ
	.proc	?f66@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f66@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=66*8,r14	// r14 = &m_pUnk->vtbl[66] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[66]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[66].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[66].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f66@_QIThunk@ATL@@UEAAJXZ


	.global ?f67@_QIThunk@ATL@@UEAAJXZ
	.proc	?f67@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f67@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=67*8,r14	// r14 = &m_pUnk->vtbl[67] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[67]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[67].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[67].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f67@_QIThunk@ATL@@UEAAJXZ


	.global ?f68@_QIThunk@ATL@@UEAAJXZ
	.proc	?f68@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f68@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=68*8,r14	// r14 = &m_pUnk->vtbl[68] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[68]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[68].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[68].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f68@_QIThunk@ATL@@UEAAJXZ


	.global ?f69@_QIThunk@ATL@@UEAAJXZ
	.proc	?f69@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f69@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=69*8,r14	// r14 = &m_pUnk->vtbl[69] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[69]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[69].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[69].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f69@_QIThunk@ATL@@UEAAJXZ


	.global ?f70@_QIThunk@ATL@@UEAAJXZ
	.proc	?f70@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f70@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=70*8,r14	// r14 = &m_pUnk->vtbl[70] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[70]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[70].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[70].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f70@_QIThunk@ATL@@UEAAJXZ


	.global ?f71@_QIThunk@ATL@@UEAAJXZ
	.proc	?f71@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f71@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=71*8,r14	// r14 = &m_pUnk->vtbl[71] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[71]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[71].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[71].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f71@_QIThunk@ATL@@UEAAJXZ


	.global ?f72@_QIThunk@ATL@@UEAAJXZ
	.proc	?f72@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f72@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=72*8,r14	// r14 = &m_pUnk->vtbl[72] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[72]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[72].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[72].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f72@_QIThunk@ATL@@UEAAJXZ


	.global ?f73@_QIThunk@ATL@@UEAAJXZ
	.proc	?f73@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f73@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=73*8,r14	// r14 = &m_pUnk->vtbl[73] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[73]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[73].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[73].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f73@_QIThunk@ATL@@UEAAJXZ


	.global ?f74@_QIThunk@ATL@@UEAAJXZ
	.proc	?f74@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f74@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=74*8,r14	// r14 = &m_pUnk->vtbl[74] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[74]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[74].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[74].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f74@_QIThunk@ATL@@UEAAJXZ


	.global ?f75@_QIThunk@ATL@@UEAAJXZ
	.proc	?f75@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f75@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=75*8,r14	// r14 = &m_pUnk->vtbl[75] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[75]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[75].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[75].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f75@_QIThunk@ATL@@UEAAJXZ


	.global ?f76@_QIThunk@ATL@@UEAAJXZ
	.proc	?f76@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f76@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=76*8,r14	// r14 = &m_pUnk->vtbl[76] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[76]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[76].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[76].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f76@_QIThunk@ATL@@UEAAJXZ


	.global ?f77@_QIThunk@ATL@@UEAAJXZ
	.proc	?f77@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f77@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=77*8,r14	// r14 = &m_pUnk->vtbl[77] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[77]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[77].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[77].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f77@_QIThunk@ATL@@UEAAJXZ


	.global ?f78@_QIThunk@ATL@@UEAAJXZ
	.proc	?f78@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f78@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=78*8,r14	// r14 = &m_pUnk->vtbl[78] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[78]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[78].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[78].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f78@_QIThunk@ATL@@UEAAJXZ


	.global ?f79@_QIThunk@ATL@@UEAAJXZ
	.proc	?f79@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f79@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=79*8,r14	// r14 = &m_pUnk->vtbl[79] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[79]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[79].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[79].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f79@_QIThunk@ATL@@UEAAJXZ


	.global ?f80@_QIThunk@ATL@@UEAAJXZ
	.proc	?f80@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f80@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=80*8,r14	// r14 = &m_pUnk->vtbl[80] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[80]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[80].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[80].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f80@_QIThunk@ATL@@UEAAJXZ


	.global ?f81@_QIThunk@ATL@@UEAAJXZ
	.proc	?f81@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f81@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=81*8,r14	// r14 = &m_pUnk->vtbl[81] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[81]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[81].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[81].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f81@_QIThunk@ATL@@UEAAJXZ


	.global ?f82@_QIThunk@ATL@@UEAAJXZ
	.proc	?f82@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f82@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=82*8,r14	// r14 = &m_pUnk->vtbl[82] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[82]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[82].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[82].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f82@_QIThunk@ATL@@UEAAJXZ


	.global ?f83@_QIThunk@ATL@@UEAAJXZ
	.proc	?f83@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f83@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=83*8,r14	// r14 = &m_pUnk->vtbl[83] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[83]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[83].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[83].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f83@_QIThunk@ATL@@UEAAJXZ


	.global ?f84@_QIThunk@ATL@@UEAAJXZ
	.proc	?f84@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f84@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=84*8,r14	// r14 = &m_pUnk->vtbl[84] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[84]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[84].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[84].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f84@_QIThunk@ATL@@UEAAJXZ


	.global ?f85@_QIThunk@ATL@@UEAAJXZ
	.proc	?f85@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f85@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=85*8,r14	// r14 = &m_pUnk->vtbl[85] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[85]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[85].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[85].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f85@_QIThunk@ATL@@UEAAJXZ


	.global ?f86@_QIThunk@ATL@@UEAAJXZ
	.proc	?f86@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f86@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=86*8,r14	// r14 = &m_pUnk->vtbl[86] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[86]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[86].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[86].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f86@_QIThunk@ATL@@UEAAJXZ


	.global ?f87@_QIThunk@ATL@@UEAAJXZ
	.proc	?f87@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f87@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=87*8,r14	// r14 = &m_pUnk->vtbl[87] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[87]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[87].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[87].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f87@_QIThunk@ATL@@UEAAJXZ


	.global ?f88@_QIThunk@ATL@@UEAAJXZ
	.proc	?f88@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f88@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=88*8,r14	// r14 = &m_pUnk->vtbl[88] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[88]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[88].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[88].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f88@_QIThunk@ATL@@UEAAJXZ


	.global ?f89@_QIThunk@ATL@@UEAAJXZ
	.proc	?f89@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f89@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=89*8,r14	// r14 = &m_pUnk->vtbl[89] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[89]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[89].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[89].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f89@_QIThunk@ATL@@UEAAJXZ


	.global ?f90@_QIThunk@ATL@@UEAAJXZ
	.proc	?f90@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f90@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=90*8,r14	// r14 = &m_pUnk->vtbl[90] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[90]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[90].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[90].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f90@_QIThunk@ATL@@UEAAJXZ


	.global ?f91@_QIThunk@ATL@@UEAAJXZ
	.proc	?f91@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f91@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=91*8,r14	// r14 = &m_pUnk->vtbl[91] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[91]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[91].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[91].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f91@_QIThunk@ATL@@UEAAJXZ


	.global ?f92@_QIThunk@ATL@@UEAAJXZ
	.proc	?f92@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f92@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=92*8,r14	// r14 = &m_pUnk->vtbl[92] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[92]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[92].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[92].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f92@_QIThunk@ATL@@UEAAJXZ


	.global ?f93@_QIThunk@ATL@@UEAAJXZ
	.proc	?f93@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f93@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=93*8,r14	// r14 = &m_pUnk->vtbl[93] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[93]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[93].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[93].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f93@_QIThunk@ATL@@UEAAJXZ


	.global ?f94@_QIThunk@ATL@@UEAAJXZ
	.proc	?f94@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f94@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=94*8,r14	// r14 = &m_pUnk->vtbl[94] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[94]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[94].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[94].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f94@_QIThunk@ATL@@UEAAJXZ


	.global ?f95@_QIThunk@ATL@@UEAAJXZ
	.proc	?f95@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f95@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=95*8,r14	// r14 = &m_pUnk->vtbl[95] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[95]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[95].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[95].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f95@_QIThunk@ATL@@UEAAJXZ


	.global ?f96@_QIThunk@ATL@@UEAAJXZ
	.proc	?f96@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f96@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=96*8,r14	// r14 = &m_pUnk->vtbl[96] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[96]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[96].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[96].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f96@_QIThunk@ATL@@UEAAJXZ


	.global ?f97@_QIThunk@ATL@@UEAAJXZ
	.proc	?f97@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f97@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=97*8,r14	// r14 = &m_pUnk->vtbl[97] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[97]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[97].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[97].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f97@_QIThunk@ATL@@UEAAJXZ


	.global ?f98@_QIThunk@ATL@@UEAAJXZ
	.proc	?f98@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f98@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=98*8,r14	// r14 = &m_pUnk->vtbl[98] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[98]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[98].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[98].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f98@_QIThunk@ATL@@UEAAJXZ


	.global ?f99@_QIThunk@ATL@@UEAAJXZ
	.proc	?f99@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f99@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=99*8,r14	// r14 = &m_pUnk->vtbl[99] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[99]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[99].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[99].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f99@_QIThunk@ATL@@UEAAJXZ


	.global ?f100@_QIThunk@ATL@@UEAAJXZ
	.proc	?f100@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f100@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=100*8,r14	// r14 = &m_pUnk->vtbl[100] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[100]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[100].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[100].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f100@_QIThunk@ATL@@UEAAJXZ


	.global ?f101@_QIThunk@ATL@@UEAAJXZ
	.proc	?f101@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f101@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=101*8,r14	// r14 = &m_pUnk->vtbl[101] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[101]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[101].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[101].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f101@_QIThunk@ATL@@UEAAJXZ


	.global ?f102@_QIThunk@ATL@@UEAAJXZ
	.proc	?f102@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f102@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=102*8,r14	// r14 = &m_pUnk->vtbl[102] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[102]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[102].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[102].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f102@_QIThunk@ATL@@UEAAJXZ


	.global ?f103@_QIThunk@ATL@@UEAAJXZ
	.proc	?f103@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f103@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=103*8,r14	// r14 = &m_pUnk->vtbl[103] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[103]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[103].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[103].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f103@_QIThunk@ATL@@UEAAJXZ


	.global ?f104@_QIThunk@ATL@@UEAAJXZ
	.proc	?f104@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f104@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=104*8,r14	// r14 = &m_pUnk->vtbl[104] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[104]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[104].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[104].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f104@_QIThunk@ATL@@UEAAJXZ


	.global ?f105@_QIThunk@ATL@@UEAAJXZ
	.proc	?f105@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f105@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=105*8,r14	// r14 = &m_pUnk->vtbl[105] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[105]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[105].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[105].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f105@_QIThunk@ATL@@UEAAJXZ


	.global ?f106@_QIThunk@ATL@@UEAAJXZ
	.proc	?f106@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f106@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=106*8,r14	// r14 = &m_pUnk->vtbl[106] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[106]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[106].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[106].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f106@_QIThunk@ATL@@UEAAJXZ


	.global ?f107@_QIThunk@ATL@@UEAAJXZ
	.proc	?f107@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f107@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=107*8,r14	// r14 = &m_pUnk->vtbl[107] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[107]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[107].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[107].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f107@_QIThunk@ATL@@UEAAJXZ


	.global ?f108@_QIThunk@ATL@@UEAAJXZ
	.proc	?f108@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f108@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=108*8,r14	// r14 = &m_pUnk->vtbl[108] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[108]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[108].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[108].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f108@_QIThunk@ATL@@UEAAJXZ


	.global ?f109@_QIThunk@ATL@@UEAAJXZ
	.proc	?f109@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f109@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=109*8,r14	// r14 = &m_pUnk->vtbl[109] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[109]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[109].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[109].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f109@_QIThunk@ATL@@UEAAJXZ


	.global ?f110@_QIThunk@ATL@@UEAAJXZ
	.proc	?f110@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f110@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=110*8,r14	// r14 = &m_pUnk->vtbl[110] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[110]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[110].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[110].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f110@_QIThunk@ATL@@UEAAJXZ


	.global ?f111@_QIThunk@ATL@@UEAAJXZ
	.proc	?f111@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f111@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=111*8,r14	// r14 = &m_pUnk->vtbl[111] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[111]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[111].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[111].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f111@_QIThunk@ATL@@UEAAJXZ


	.global ?f112@_QIThunk@ATL@@UEAAJXZ
	.proc	?f112@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f112@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=112*8,r14	// r14 = &m_pUnk->vtbl[112] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[112]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[112].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[112].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f112@_QIThunk@ATL@@UEAAJXZ


	.global ?f113@_QIThunk@ATL@@UEAAJXZ
	.proc	?f113@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f113@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=113*8,r14	// r14 = &m_pUnk->vtbl[113] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[113]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[113].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[113].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f113@_QIThunk@ATL@@UEAAJXZ


	.global ?f114@_QIThunk@ATL@@UEAAJXZ
	.proc	?f114@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f114@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=114*8,r14	// r14 = &m_pUnk->vtbl[114] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[114]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[114].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[114].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f114@_QIThunk@ATL@@UEAAJXZ


	.global ?f115@_QIThunk@ATL@@UEAAJXZ
	.proc	?f115@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f115@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=115*8,r14	// r14 = &m_pUnk->vtbl[115] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[115]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[115].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[115].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f115@_QIThunk@ATL@@UEAAJXZ


	.global ?f116@_QIThunk@ATL@@UEAAJXZ
	.proc	?f116@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f116@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=116*8,r14	// r14 = &m_pUnk->vtbl[116] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[116]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[116].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[116].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f116@_QIThunk@ATL@@UEAAJXZ


	.global ?f117@_QIThunk@ATL@@UEAAJXZ
	.proc	?f117@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f117@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=117*8,r14	// r14 = &m_pUnk->vtbl[117] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[117]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[117].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[117].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f117@_QIThunk@ATL@@UEAAJXZ


	.global ?f118@_QIThunk@ATL@@UEAAJXZ
	.proc	?f118@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f118@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=118*8,r14	// r14 = &m_pUnk->vtbl[118] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[118]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[118].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[118].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f118@_QIThunk@ATL@@UEAAJXZ


	.global ?f119@_QIThunk@ATL@@UEAAJXZ
	.proc	?f119@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f119@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=119*8,r14	// r14 = &m_pUnk->vtbl[119] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[119]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[119].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[119].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f119@_QIThunk@ATL@@UEAAJXZ


	.global ?f120@_QIThunk@ATL@@UEAAJXZ
	.proc	?f120@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f120@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=120*8,r14	// r14 = &m_pUnk->vtbl[120] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[120]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[120].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[120].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f120@_QIThunk@ATL@@UEAAJXZ


	.global ?f121@_QIThunk@ATL@@UEAAJXZ
	.proc	?f121@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f121@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=121*8,r14	// r14 = &m_pUnk->vtbl[121] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[121]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[121].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[121].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f121@_QIThunk@ATL@@UEAAJXZ


	.global ?f122@_QIThunk@ATL@@UEAAJXZ
	.proc	?f122@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f122@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=122*8,r14	// r14 = &m_pUnk->vtbl[122] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[122]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[122].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[122].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f122@_QIThunk@ATL@@UEAAJXZ


	.global ?f123@_QIThunk@ATL@@UEAAJXZ
	.proc	?f123@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f123@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=123*8,r14	// r14 = &m_pUnk->vtbl[123] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[123]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[123].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[123].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f123@_QIThunk@ATL@@UEAAJXZ


	.global ?f124@_QIThunk@ATL@@UEAAJXZ
	.proc	?f124@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f124@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=124*8,r14	// r14 = &m_pUnk->vtbl[124] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[124]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[124].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[124].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f124@_QIThunk@ATL@@UEAAJXZ


	.global ?f125@_QIThunk@ATL@@UEAAJXZ
	.proc	?f125@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f125@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=125*8,r14	// r14 = &m_pUnk->vtbl[125] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[125]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[125].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[125].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f125@_QIThunk@ATL@@UEAAJXZ


	.global ?f126@_QIThunk@ATL@@UEAAJXZ
	.proc	?f126@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f126@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=126*8,r14	// r14 = &m_pUnk->vtbl[126] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[126]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[126].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[126].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f126@_QIThunk@ATL@@UEAAJXZ


	.global ?f127@_QIThunk@ATL@@UEAAJXZ
	.proc	?f127@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f127@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=127*8,r14	// r14 = &m_pUnk->vtbl[127] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[127]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[127].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[127].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f127@_QIThunk@ATL@@UEAAJXZ


	.global ?f128@_QIThunk@ATL@@UEAAJXZ
	.proc	?f128@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f128@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=128*8,r14	// r14 = &m_pUnk->vtbl[128] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[128]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[128].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[128].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f128@_QIThunk@ATL@@UEAAJXZ


	.global ?f129@_QIThunk@ATL@@UEAAJXZ
	.proc	?f129@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f129@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=129*8,r14	// r14 = &m_pUnk->vtbl[129] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[129]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[129].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[129].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f129@_QIThunk@ATL@@UEAAJXZ


	.global ?f130@_QIThunk@ATL@@UEAAJXZ
	.proc	?f130@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f130@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=130*8,r14	// r14 = &m_pUnk->vtbl[130] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[130]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[130].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[130].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f130@_QIThunk@ATL@@UEAAJXZ


	.global ?f131@_QIThunk@ATL@@UEAAJXZ
	.proc	?f131@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f131@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=131*8,r14	// r14 = &m_pUnk->vtbl[131] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[131]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[131].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[131].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f131@_QIThunk@ATL@@UEAAJXZ


	.global ?f132@_QIThunk@ATL@@UEAAJXZ
	.proc	?f132@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f132@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=132*8,r14	// r14 = &m_pUnk->vtbl[132] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[132]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[132].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[132].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f132@_QIThunk@ATL@@UEAAJXZ


	.global ?f133@_QIThunk@ATL@@UEAAJXZ
	.proc	?f133@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f133@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=133*8,r14	// r14 = &m_pUnk->vtbl[133] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[133]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[133].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[133].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f133@_QIThunk@ATL@@UEAAJXZ


	.global ?f134@_QIThunk@ATL@@UEAAJXZ
	.proc	?f134@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f134@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=134*8,r14	// r14 = &m_pUnk->vtbl[134] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[134]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[134].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[134].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f134@_QIThunk@ATL@@UEAAJXZ


	.global ?f135@_QIThunk@ATL@@UEAAJXZ
	.proc	?f135@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f135@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=135*8,r14	// r14 = &m_pUnk->vtbl[135] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[135]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[135].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[135].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f135@_QIThunk@ATL@@UEAAJXZ


	.global ?f136@_QIThunk@ATL@@UEAAJXZ
	.proc	?f136@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f136@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=136*8,r14	// r14 = &m_pUnk->vtbl[136] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[136]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[136].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[136].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f136@_QIThunk@ATL@@UEAAJXZ


	.global ?f137@_QIThunk@ATL@@UEAAJXZ
	.proc	?f137@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f137@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=137*8,r14	// r14 = &m_pUnk->vtbl[137] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[137]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[137].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[137].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f137@_QIThunk@ATL@@UEAAJXZ


	.global ?f138@_QIThunk@ATL@@UEAAJXZ
	.proc	?f138@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f138@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=138*8,r14	// r14 = &m_pUnk->vtbl[138] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[138]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[138].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[138].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f138@_QIThunk@ATL@@UEAAJXZ


	.global ?f139@_QIThunk@ATL@@UEAAJXZ
	.proc	?f139@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f139@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=139*8,r14	// r14 = &m_pUnk->vtbl[139] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[139]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[139].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[139].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f139@_QIThunk@ATL@@UEAAJXZ


	.global ?f140@_QIThunk@ATL@@UEAAJXZ
	.proc	?f140@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f140@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=140*8,r14	// r14 = &m_pUnk->vtbl[140] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[140]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[140].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[140].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f140@_QIThunk@ATL@@UEAAJXZ


	.global ?f141@_QIThunk@ATL@@UEAAJXZ
	.proc	?f141@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f141@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=141*8,r14	// r14 = &m_pUnk->vtbl[141] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[141]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[141].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[141].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f141@_QIThunk@ATL@@UEAAJXZ


	.global ?f142@_QIThunk@ATL@@UEAAJXZ
	.proc	?f142@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f142@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=142*8,r14	// r14 = &m_pUnk->vtbl[142] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[142]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[142].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[142].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f142@_QIThunk@ATL@@UEAAJXZ


	.global ?f143@_QIThunk@ATL@@UEAAJXZ
	.proc	?f143@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f143@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=143*8,r14	// r14 = &m_pUnk->vtbl[143] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[143]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[143].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[143].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f143@_QIThunk@ATL@@UEAAJXZ


	.global ?f144@_QIThunk@ATL@@UEAAJXZ
	.proc	?f144@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f144@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=144*8,r14	// r14 = &m_pUnk->vtbl[144] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[144]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[144].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[144].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f144@_QIThunk@ATL@@UEAAJXZ


	.global ?f145@_QIThunk@ATL@@UEAAJXZ
	.proc	?f145@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f145@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=145*8,r14	// r14 = &m_pUnk->vtbl[145] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[145]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[145].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[145].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f145@_QIThunk@ATL@@UEAAJXZ


	.global ?f146@_QIThunk@ATL@@UEAAJXZ
	.proc	?f146@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f146@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=146*8,r14	// r14 = &m_pUnk->vtbl[146] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[146]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[146].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[146].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f146@_QIThunk@ATL@@UEAAJXZ


	.global ?f147@_QIThunk@ATL@@UEAAJXZ
	.proc	?f147@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f147@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=147*8,r14	// r14 = &m_pUnk->vtbl[147] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[147]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[147].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[147].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f147@_QIThunk@ATL@@UEAAJXZ


	.global ?f148@_QIThunk@ATL@@UEAAJXZ
	.proc	?f148@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f148@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=148*8,r14	// r14 = &m_pUnk->vtbl[148] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[148]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[148].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[148].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f148@_QIThunk@ATL@@UEAAJXZ


	.global ?f149@_QIThunk@ATL@@UEAAJXZ
	.proc	?f149@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f149@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=149*8,r14	// r14 = &m_pUnk->vtbl[149] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[149]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[149].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[149].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f149@_QIThunk@ATL@@UEAAJXZ


	.global ?f150@_QIThunk@ATL@@UEAAJXZ
	.proc	?f150@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f150@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=150*8,r14	// r14 = &m_pUnk->vtbl[150] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[150]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[150].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[150].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f150@_QIThunk@ATL@@UEAAJXZ


	.global ?f151@_QIThunk@ATL@@UEAAJXZ
	.proc	?f151@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f151@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=151*8,r14	// r14 = &m_pUnk->vtbl[151] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[151]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[151].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[151].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f151@_QIThunk@ATL@@UEAAJXZ


	.global ?f152@_QIThunk@ATL@@UEAAJXZ
	.proc	?f152@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f152@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=152*8,r14	// r14 = &m_pUnk->vtbl[152] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[152]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[152].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[152].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f152@_QIThunk@ATL@@UEAAJXZ


	.global ?f153@_QIThunk@ATL@@UEAAJXZ
	.proc	?f153@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f153@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=153*8,r14	// r14 = &m_pUnk->vtbl[153] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[153]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[153].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[153].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f153@_QIThunk@ATL@@UEAAJXZ


	.global ?f154@_QIThunk@ATL@@UEAAJXZ
	.proc	?f154@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f154@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=154*8,r14	// r14 = &m_pUnk->vtbl[154] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[154]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[154].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[154].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f154@_QIThunk@ATL@@UEAAJXZ


	.global ?f155@_QIThunk@ATL@@UEAAJXZ
	.proc	?f155@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f155@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=155*8,r14	// r14 = &m_pUnk->vtbl[155] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[155]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[155].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[155].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f155@_QIThunk@ATL@@UEAAJXZ


	.global ?f156@_QIThunk@ATL@@UEAAJXZ
	.proc	?f156@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f156@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=156*8,r14	// r14 = &m_pUnk->vtbl[156] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[156]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[156].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[156].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f156@_QIThunk@ATL@@UEAAJXZ


	.global ?f157@_QIThunk@ATL@@UEAAJXZ
	.proc	?f157@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f157@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=157*8,r14	// r14 = &m_pUnk->vtbl[157] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[157]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[157].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[157].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f157@_QIThunk@ATL@@UEAAJXZ


	.global ?f158@_QIThunk@ATL@@UEAAJXZ
	.proc	?f158@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f158@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=158*8,r14	// r14 = &m_pUnk->vtbl[158] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[158]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[158].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[158].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f158@_QIThunk@ATL@@UEAAJXZ


	.global ?f159@_QIThunk@ATL@@UEAAJXZ
	.proc	?f159@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f159@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=159*8,r14	// r14 = &m_pUnk->vtbl[159] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[159]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[159].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[159].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f159@_QIThunk@ATL@@UEAAJXZ


	.global ?f160@_QIThunk@ATL@@UEAAJXZ
	.proc	?f160@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f160@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=160*8,r14	// r14 = &m_pUnk->vtbl[160] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[160]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[160].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[160].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f160@_QIThunk@ATL@@UEAAJXZ


	.global ?f161@_QIThunk@ATL@@UEAAJXZ
	.proc	?f161@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f161@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=161*8,r14	// r14 = &m_pUnk->vtbl[161] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[161]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[161].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[161].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f161@_QIThunk@ATL@@UEAAJXZ


	.global ?f162@_QIThunk@ATL@@UEAAJXZ
	.proc	?f162@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f162@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=162*8,r14	// r14 = &m_pUnk->vtbl[162] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[162]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[162].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[162].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f162@_QIThunk@ATL@@UEAAJXZ


	.global ?f163@_QIThunk@ATL@@UEAAJXZ
	.proc	?f163@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f163@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=163*8,r14	// r14 = &m_pUnk->vtbl[163] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[163]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[163].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[163].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f163@_QIThunk@ATL@@UEAAJXZ


	.global ?f164@_QIThunk@ATL@@UEAAJXZ
	.proc	?f164@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f164@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=164*8,r14	// r14 = &m_pUnk->vtbl[164] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[164]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[164].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[164].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f164@_QIThunk@ATL@@UEAAJXZ


	.global ?f165@_QIThunk@ATL@@UEAAJXZ
	.proc	?f165@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f165@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=165*8,r14	// r14 = &m_pUnk->vtbl[165] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[165]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[165].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[165].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f165@_QIThunk@ATL@@UEAAJXZ


	.global ?f166@_QIThunk@ATL@@UEAAJXZ
	.proc	?f166@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f166@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=166*8,r14	// r14 = &m_pUnk->vtbl[166] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[166]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[166].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[166].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f166@_QIThunk@ATL@@UEAAJXZ


	.global ?f167@_QIThunk@ATL@@UEAAJXZ
	.proc	?f167@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f167@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=167*8,r14	// r14 = &m_pUnk->vtbl[167] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[167]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[167].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[167].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f167@_QIThunk@ATL@@UEAAJXZ


	.global ?f168@_QIThunk@ATL@@UEAAJXZ
	.proc	?f168@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f168@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=168*8,r14	// r14 = &m_pUnk->vtbl[168] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[168]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[168].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[168].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f168@_QIThunk@ATL@@UEAAJXZ


	.global ?f169@_QIThunk@ATL@@UEAAJXZ
	.proc	?f169@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f169@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=169*8,r14	// r14 = &m_pUnk->vtbl[169] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[169]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[169].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[169].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f169@_QIThunk@ATL@@UEAAJXZ


	.global ?f170@_QIThunk@ATL@@UEAAJXZ
	.proc	?f170@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f170@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=170*8,r14	// r14 = &m_pUnk->vtbl[170] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[170]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[170].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[170].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f170@_QIThunk@ATL@@UEAAJXZ


	.global ?f171@_QIThunk@ATL@@UEAAJXZ
	.proc	?f171@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f171@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=171*8,r14	// r14 = &m_pUnk->vtbl[171] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[171]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[171].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[171].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f171@_QIThunk@ATL@@UEAAJXZ


	.global ?f172@_QIThunk@ATL@@UEAAJXZ
	.proc	?f172@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f172@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=172*8,r14	// r14 = &m_pUnk->vtbl[172] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[172]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[172].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[172].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f172@_QIThunk@ATL@@UEAAJXZ


	.global ?f173@_QIThunk@ATL@@UEAAJXZ
	.proc	?f173@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f173@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=173*8,r14	// r14 = &m_pUnk->vtbl[173] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[173]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[173].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[173].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f173@_QIThunk@ATL@@UEAAJXZ


	.global ?f174@_QIThunk@ATL@@UEAAJXZ
	.proc	?f174@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f174@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=174*8,r14	// r14 = &m_pUnk->vtbl[174] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[174]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[174].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[174].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f174@_QIThunk@ATL@@UEAAJXZ


	.global ?f175@_QIThunk@ATL@@UEAAJXZ
	.proc	?f175@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f175@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=175*8,r14	// r14 = &m_pUnk->vtbl[175] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[175]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[175].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[175].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f175@_QIThunk@ATL@@UEAAJXZ


	.global ?f176@_QIThunk@ATL@@UEAAJXZ
	.proc	?f176@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f176@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=176*8,r14	// r14 = &m_pUnk->vtbl[176] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[176]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[176].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[176].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f176@_QIThunk@ATL@@UEAAJXZ


	.global ?f177@_QIThunk@ATL@@UEAAJXZ
	.proc	?f177@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f177@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=177*8,r14	// r14 = &m_pUnk->vtbl[177] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[177]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[177].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[177].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f177@_QIThunk@ATL@@UEAAJXZ


	.global ?f178@_QIThunk@ATL@@UEAAJXZ
	.proc	?f178@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f178@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=178*8,r14	// r14 = &m_pUnk->vtbl[178] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[178]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[178].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[178].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f178@_QIThunk@ATL@@UEAAJXZ


	.global ?f179@_QIThunk@ATL@@UEAAJXZ
	.proc	?f179@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f179@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=179*8,r14	// r14 = &m_pUnk->vtbl[179] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[179]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[179].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[179].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f179@_QIThunk@ATL@@UEAAJXZ


	.global ?f180@_QIThunk@ATL@@UEAAJXZ
	.proc	?f180@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f180@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=180*8,r14	// r14 = &m_pUnk->vtbl[180] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[180]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[180].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[180].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f180@_QIThunk@ATL@@UEAAJXZ


	.global ?f181@_QIThunk@ATL@@UEAAJXZ
	.proc	?f181@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f181@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=181*8,r14	// r14 = &m_pUnk->vtbl[181] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[181]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[181].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[181].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f181@_QIThunk@ATL@@UEAAJXZ


	.global ?f182@_QIThunk@ATL@@UEAAJXZ
	.proc	?f182@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f182@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=182*8,r14	// r14 = &m_pUnk->vtbl[182] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[182]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[182].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[182].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f182@_QIThunk@ATL@@UEAAJXZ


	.global ?f183@_QIThunk@ATL@@UEAAJXZ
	.proc	?f183@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f183@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=183*8,r14	// r14 = &m_pUnk->vtbl[183] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[183]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[183].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[183].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f183@_QIThunk@ATL@@UEAAJXZ


	.global ?f184@_QIThunk@ATL@@UEAAJXZ
	.proc	?f184@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f184@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=184*8,r14	// r14 = &m_pUnk->vtbl[184] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[184]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[184].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[184].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f184@_QIThunk@ATL@@UEAAJXZ


	.global ?f185@_QIThunk@ATL@@UEAAJXZ
	.proc	?f185@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f185@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=185*8,r14	// r14 = &m_pUnk->vtbl[185] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[185]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[185].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[185].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f185@_QIThunk@ATL@@UEAAJXZ


	.global ?f186@_QIThunk@ATL@@UEAAJXZ
	.proc	?f186@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f186@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=186*8,r14	// r14 = &m_pUnk->vtbl[186] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[186]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[186].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[186].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f186@_QIThunk@ATL@@UEAAJXZ


	.global ?f187@_QIThunk@ATL@@UEAAJXZ
	.proc	?f187@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f187@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=187*8,r14	// r14 = &m_pUnk->vtbl[187] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[187]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[187].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[187].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f187@_QIThunk@ATL@@UEAAJXZ


	.global ?f188@_QIThunk@ATL@@UEAAJXZ
	.proc	?f188@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f188@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=188*8,r14	// r14 = &m_pUnk->vtbl[188] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[188]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[188].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[188].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f188@_QIThunk@ATL@@UEAAJXZ


	.global ?f189@_QIThunk@ATL@@UEAAJXZ
	.proc	?f189@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f189@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=189*8,r14	// r14 = &m_pUnk->vtbl[189] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[189]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[189].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[189].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f189@_QIThunk@ATL@@UEAAJXZ


	.global ?f190@_QIThunk@ATL@@UEAAJXZ
	.proc	?f190@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f190@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=190*8,r14	// r14 = &m_pUnk->vtbl[190] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[190]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[190].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[190].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f190@_QIThunk@ATL@@UEAAJXZ


	.global ?f191@_QIThunk@ATL@@UEAAJXZ
	.proc	?f191@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f191@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=191*8,r14	// r14 = &m_pUnk->vtbl[191] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[191]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[191].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[191].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f191@_QIThunk@ATL@@UEAAJXZ


	.global ?f192@_QIThunk@ATL@@UEAAJXZ
	.proc	?f192@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f192@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=192*8,r14	// r14 = &m_pUnk->vtbl[192] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[192]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[192].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[192].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f192@_QIThunk@ATL@@UEAAJXZ


	.global ?f193@_QIThunk@ATL@@UEAAJXZ
	.proc	?f193@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f193@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=193*8,r14	// r14 = &m_pUnk->vtbl[193] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[193]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[193].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[193].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f193@_QIThunk@ATL@@UEAAJXZ


	.global ?f194@_QIThunk@ATL@@UEAAJXZ
	.proc	?f194@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f194@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=194*8,r14	// r14 = &m_pUnk->vtbl[194] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[194]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[194].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[194].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f194@_QIThunk@ATL@@UEAAJXZ


	.global ?f195@_QIThunk@ATL@@UEAAJXZ
	.proc	?f195@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f195@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=195*8,r14	// r14 = &m_pUnk->vtbl[195] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[195]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[195].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[195].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f195@_QIThunk@ATL@@UEAAJXZ


	.global ?f196@_QIThunk@ATL@@UEAAJXZ
	.proc	?f196@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f196@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=196*8,r14	// r14 = &m_pUnk->vtbl[196] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[196]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[196].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[196].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f196@_QIThunk@ATL@@UEAAJXZ


	.global ?f197@_QIThunk@ATL@@UEAAJXZ
	.proc	?f197@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f197@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=197*8,r14	// r14 = &m_pUnk->vtbl[197] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[197]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[197].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[197].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f197@_QIThunk@ATL@@UEAAJXZ


	.global ?f198@_QIThunk@ATL@@UEAAJXZ
	.proc	?f198@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f198@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=198*8,r14	// r14 = &m_pUnk->vtbl[198] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[198]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[198].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[198].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f198@_QIThunk@ATL@@UEAAJXZ


	.global ?f199@_QIThunk@ATL@@UEAAJXZ
	.proc	?f199@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f199@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=199*8,r14	// r14 = &m_pUnk->vtbl[199] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[199]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[199].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[199].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f199@_QIThunk@ATL@@UEAAJXZ


	.global ?f200@_QIThunk@ATL@@UEAAJXZ
	.proc	?f200@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f200@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=200*8,r14	// r14 = &m_pUnk->vtbl[200] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[200]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[200].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[200].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f200@_QIThunk@ATL@@UEAAJXZ


	.global ?f201@_QIThunk@ATL@@UEAAJXZ
	.proc	?f201@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f201@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=201*8,r14	// r14 = &m_pUnk->vtbl[201] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[201]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[201].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[201].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f201@_QIThunk@ATL@@UEAAJXZ


	.global ?f202@_QIThunk@ATL@@UEAAJXZ
	.proc	?f202@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f202@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=202*8,r14	// r14 = &m_pUnk->vtbl[202] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[202]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[202].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[202].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f202@_QIThunk@ATL@@UEAAJXZ


	.global ?f203@_QIThunk@ATL@@UEAAJXZ
	.proc	?f203@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f203@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=203*8,r14	// r14 = &m_pUnk->vtbl[203] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[203]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[203].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[203].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f203@_QIThunk@ATL@@UEAAJXZ


	.global ?f204@_QIThunk@ATL@@UEAAJXZ
	.proc	?f204@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f204@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=204*8,r14	// r14 = &m_pUnk->vtbl[204] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[204]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[204].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[204].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f204@_QIThunk@ATL@@UEAAJXZ


	.global ?f205@_QIThunk@ATL@@UEAAJXZ
	.proc	?f205@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f205@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=205*8,r14	// r14 = &m_pUnk->vtbl[205] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[205]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[205].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[205].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f205@_QIThunk@ATL@@UEAAJXZ


	.global ?f206@_QIThunk@ATL@@UEAAJXZ
	.proc	?f206@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f206@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=206*8,r14	// r14 = &m_pUnk->vtbl[206] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[206]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[206].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[206].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f206@_QIThunk@ATL@@UEAAJXZ


	.global ?f207@_QIThunk@ATL@@UEAAJXZ
	.proc	?f207@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f207@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=207*8,r14	// r14 = &m_pUnk->vtbl[207] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[207]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[207].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[207].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f207@_QIThunk@ATL@@UEAAJXZ


	.global ?f208@_QIThunk@ATL@@UEAAJXZ
	.proc	?f208@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f208@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=208*8,r14	// r14 = &m_pUnk->vtbl[208] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[208]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[208].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[208].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f208@_QIThunk@ATL@@UEAAJXZ


	.global ?f209@_QIThunk@ATL@@UEAAJXZ
	.proc	?f209@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f209@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=209*8,r14	// r14 = &m_pUnk->vtbl[209] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[209]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[209].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[209].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f209@_QIThunk@ATL@@UEAAJXZ


	.global ?f210@_QIThunk@ATL@@UEAAJXZ
	.proc	?f210@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f210@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=210*8,r14	// r14 = &m_pUnk->vtbl[210] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[210]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[210].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[210].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f210@_QIThunk@ATL@@UEAAJXZ


	.global ?f211@_QIThunk@ATL@@UEAAJXZ
	.proc	?f211@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f211@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=211*8,r14	// r14 = &m_pUnk->vtbl[211] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[211]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[211].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[211].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f211@_QIThunk@ATL@@UEAAJXZ


	.global ?f212@_QIThunk@ATL@@UEAAJXZ
	.proc	?f212@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f212@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=212*8,r14	// r14 = &m_pUnk->vtbl[212] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[212]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[212].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[212].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f212@_QIThunk@ATL@@UEAAJXZ


	.global ?f213@_QIThunk@ATL@@UEAAJXZ
	.proc	?f213@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f213@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=213*8,r14	// r14 = &m_pUnk->vtbl[213] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[213]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[213].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[213].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f213@_QIThunk@ATL@@UEAAJXZ


	.global ?f214@_QIThunk@ATL@@UEAAJXZ
	.proc	?f214@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f214@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=214*8,r14	// r14 = &m_pUnk->vtbl[214] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[214]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[214].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[214].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f214@_QIThunk@ATL@@UEAAJXZ


	.global ?f215@_QIThunk@ATL@@UEAAJXZ
	.proc	?f215@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f215@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=215*8,r14	// r14 = &m_pUnk->vtbl[215] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[215]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[215].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[215].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f215@_QIThunk@ATL@@UEAAJXZ


	.global ?f216@_QIThunk@ATL@@UEAAJXZ
	.proc	?f216@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f216@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=216*8,r14	// r14 = &m_pUnk->vtbl[216] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[216]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[216].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[216].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f216@_QIThunk@ATL@@UEAAJXZ


	.global ?f217@_QIThunk@ATL@@UEAAJXZ
	.proc	?f217@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f217@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=217*8,r14	// r14 = &m_pUnk->vtbl[217] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[217]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[217].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[217].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f217@_QIThunk@ATL@@UEAAJXZ


	.global ?f218@_QIThunk@ATL@@UEAAJXZ
	.proc	?f218@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f218@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=218*8,r14	// r14 = &m_pUnk->vtbl[218] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[218]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[218].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[218].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f218@_QIThunk@ATL@@UEAAJXZ


	.global ?f219@_QIThunk@ATL@@UEAAJXZ
	.proc	?f219@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f219@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=219*8,r14	// r14 = &m_pUnk->vtbl[219] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[219]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[219].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[219].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f219@_QIThunk@ATL@@UEAAJXZ


	.global ?f220@_QIThunk@ATL@@UEAAJXZ
	.proc	?f220@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f220@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=220*8,r14	// r14 = &m_pUnk->vtbl[220] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[220]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[220].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[220].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f220@_QIThunk@ATL@@UEAAJXZ


	.global ?f221@_QIThunk@ATL@@UEAAJXZ
	.proc	?f221@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f221@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=221*8,r14	// r14 = &m_pUnk->vtbl[221] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[221]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[221].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[221].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f221@_QIThunk@ATL@@UEAAJXZ


	.global ?f222@_QIThunk@ATL@@UEAAJXZ
	.proc	?f222@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f222@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=222*8,r14	// r14 = &m_pUnk->vtbl[222] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[222]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[222].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[222].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f222@_QIThunk@ATL@@UEAAJXZ


	.global ?f223@_QIThunk@ATL@@UEAAJXZ
	.proc	?f223@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f223@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=223*8,r14	// r14 = &m_pUnk->vtbl[223] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[223]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[223].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[223].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f223@_QIThunk@ATL@@UEAAJXZ


	.global ?f224@_QIThunk@ATL@@UEAAJXZ
	.proc	?f224@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f224@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=224*8,r14	// r14 = &m_pUnk->vtbl[224] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[224]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[224].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[224].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f224@_QIThunk@ATL@@UEAAJXZ


	.global ?f225@_QIThunk@ATL@@UEAAJXZ
	.proc	?f225@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f225@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=225*8,r14	// r14 = &m_pUnk->vtbl[225] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[225]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[225].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[225].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f225@_QIThunk@ATL@@UEAAJXZ


	.global ?f226@_QIThunk@ATL@@UEAAJXZ
	.proc	?f226@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f226@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=226*8,r14	// r14 = &m_pUnk->vtbl[226] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[226]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[226].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[226].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f226@_QIThunk@ATL@@UEAAJXZ


	.global ?f227@_QIThunk@ATL@@UEAAJXZ
	.proc	?f227@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f227@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=227*8,r14	// r14 = &m_pUnk->vtbl[227] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[227]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[227].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[227].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f227@_QIThunk@ATL@@UEAAJXZ


	.global ?f228@_QIThunk@ATL@@UEAAJXZ
	.proc	?f228@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f228@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=228*8,r14	// r14 = &m_pUnk->vtbl[228] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[228]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[228].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[228].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f228@_QIThunk@ATL@@UEAAJXZ


	.global ?f229@_QIThunk@ATL@@UEAAJXZ
	.proc	?f229@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f229@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=229*8,r14	// r14 = &m_pUnk->vtbl[229] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[229]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[229].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[229].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f229@_QIThunk@ATL@@UEAAJXZ


	.global ?f230@_QIThunk@ATL@@UEAAJXZ
	.proc	?f230@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f230@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=230*8,r14	// r14 = &m_pUnk->vtbl[230] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[230]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[230].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[230].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f230@_QIThunk@ATL@@UEAAJXZ


	.global ?f231@_QIThunk@ATL@@UEAAJXZ
	.proc	?f231@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f231@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=231*8,r14	// r14 = &m_pUnk->vtbl[231] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[231]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[231].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[231].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f231@_QIThunk@ATL@@UEAAJXZ


	.global ?f232@_QIThunk@ATL@@UEAAJXZ
	.proc	?f232@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f232@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=232*8,r14	// r14 = &m_pUnk->vtbl[232] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[232]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[232].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[232].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f232@_QIThunk@ATL@@UEAAJXZ


	.global ?f233@_QIThunk@ATL@@UEAAJXZ
	.proc	?f233@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f233@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=233*8,r14	// r14 = &m_pUnk->vtbl[233] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[233]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[233].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[233].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f233@_QIThunk@ATL@@UEAAJXZ


	.global ?f234@_QIThunk@ATL@@UEAAJXZ
	.proc	?f234@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f234@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=234*8,r14	// r14 = &m_pUnk->vtbl[234] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[234]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[234].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[234].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f234@_QIThunk@ATL@@UEAAJXZ


	.global ?f235@_QIThunk@ATL@@UEAAJXZ
	.proc	?f235@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f235@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=235*8,r14	// r14 = &m_pUnk->vtbl[235] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[235]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[235].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[235].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f235@_QIThunk@ATL@@UEAAJXZ


	.global ?f236@_QIThunk@ATL@@UEAAJXZ
	.proc	?f236@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f236@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=236*8,r14	// r14 = &m_pUnk->vtbl[236] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[236]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[236].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[236].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f236@_QIThunk@ATL@@UEAAJXZ


	.global ?f237@_QIThunk@ATL@@UEAAJXZ
	.proc	?f237@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f237@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=237*8,r14	// r14 = &m_pUnk->vtbl[237] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[237]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[237].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[237].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f237@_QIThunk@ATL@@UEAAJXZ


	.global ?f238@_QIThunk@ATL@@UEAAJXZ
	.proc	?f238@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f238@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=238*8,r14	// r14 = &m_pUnk->vtbl[238] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[238]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[238].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[238].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f238@_QIThunk@ATL@@UEAAJXZ


	.global ?f239@_QIThunk@ATL@@UEAAJXZ
	.proc	?f239@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f239@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=239*8,r14	// r14 = &m_pUnk->vtbl[239] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[239]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[239].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[239].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f239@_QIThunk@ATL@@UEAAJXZ


	.global ?f240@_QIThunk@ATL@@UEAAJXZ
	.proc	?f240@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f240@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=240*8,r14	// r14 = &m_pUnk->vtbl[240] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[240]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[240].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[240].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f240@_QIThunk@ATL@@UEAAJXZ


	.global ?f241@_QIThunk@ATL@@UEAAJXZ
	.proc	?f241@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f241@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=241*8,r14	// r14 = &m_pUnk->vtbl[241] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[241]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[241].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[241].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f241@_QIThunk@ATL@@UEAAJXZ


	.global ?f242@_QIThunk@ATL@@UEAAJXZ
	.proc	?f242@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f242@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=242*8,r14	// r14 = &m_pUnk->vtbl[242] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[242]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[242].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[242].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f242@_QIThunk@ATL@@UEAAJXZ


	.global ?f243@_QIThunk@ATL@@UEAAJXZ
	.proc	?f243@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f243@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=243*8,r14	// r14 = &m_pUnk->vtbl[243] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[243]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[243].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[243].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f243@_QIThunk@ATL@@UEAAJXZ


	.global ?f244@_QIThunk@ATL@@UEAAJXZ
	.proc	?f244@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f244@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=244*8,r14	// r14 = &m_pUnk->vtbl[244] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[244]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[244].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[244].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f244@_QIThunk@ATL@@UEAAJXZ


	.global ?f245@_QIThunk@ATL@@UEAAJXZ
	.proc	?f245@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f245@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=245*8,r14	// r14 = &m_pUnk->vtbl[245] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[245]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[245].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[245].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f245@_QIThunk@ATL@@UEAAJXZ


	.global ?f246@_QIThunk@ATL@@UEAAJXZ
	.proc	?f246@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f246@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=246*8,r14	// r14 = &m_pUnk->vtbl[246] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[246]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[246].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[246].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f246@_QIThunk@ATL@@UEAAJXZ


	.global ?f247@_QIThunk@ATL@@UEAAJXZ
	.proc	?f247@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f247@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=247*8,r14	// r14 = &m_pUnk->vtbl[247] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[247]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[247].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[247].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f247@_QIThunk@ATL@@UEAAJXZ


	.global ?f248@_QIThunk@ATL@@UEAAJXZ
	.proc	?f248@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f248@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=248*8,r14	// r14 = &m_pUnk->vtbl[248] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[248]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[248].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[248].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f248@_QIThunk@ATL@@UEAAJXZ


	.global ?f249@_QIThunk@ATL@@UEAAJXZ
	.proc	?f249@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f249@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=249*8,r14	// r14 = &m_pUnk->vtbl[249] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[249]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[249].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[249].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f249@_QIThunk@ATL@@UEAAJXZ


	.global ?f250@_QIThunk@ATL@@UEAAJXZ
	.proc	?f250@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f250@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=250*8,r14	// r14 = &m_pUnk->vtbl[250] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[250]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[250].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[250].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f250@_QIThunk@ATL@@UEAAJXZ


	.global ?f251@_QIThunk@ATL@@UEAAJXZ
	.proc	?f251@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f251@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=251*8,r14	// r14 = &m_pUnk->vtbl[251] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[251]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[251].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[251].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f251@_QIThunk@ATL@@UEAAJXZ


	.global ?f252@_QIThunk@ATL@@UEAAJXZ
	.proc	?f252@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f252@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=252*8,r14	// r14 = &m_pUnk->vtbl[252] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[252]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[252].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[252].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f252@_QIThunk@ATL@@UEAAJXZ


	.global ?f253@_QIThunk@ATL@@UEAAJXZ
	.proc	?f253@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f253@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=253*8,r14	// r14 = &m_pUnk->vtbl[253] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[253]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[253].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[253].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f253@_QIThunk@ATL@@UEAAJXZ


	.global ?f254@_QIThunk@ATL@@UEAAJXZ
	.proc	?f254@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f254@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=254*8,r14	// r14 = &m_pUnk->vtbl[254] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[254]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[254].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[254].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f254@_QIThunk@ATL@@UEAAJXZ


	.global ?f255@_QIThunk@ATL@@UEAAJXZ
	.proc	?f255@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f255@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=255*8,r14	// r14 = &m_pUnk->vtbl[255] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[255]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[255].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[255].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f255@_QIThunk@ATL@@UEAAJXZ


	.global ?f256@_QIThunk@ATL@@UEAAJXZ
	.proc	?f256@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f256@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=256*8,r14	// r14 = &m_pUnk->vtbl[256] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[256]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[256].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[256].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f256@_QIThunk@ATL@@UEAAJXZ


	.global ?f257@_QIThunk@ATL@@UEAAJXZ
	.proc	?f257@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f257@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=257*8,r14	// r14 = &m_pUnk->vtbl[257] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[257]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[257].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[257].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f257@_QIThunk@ATL@@UEAAJXZ


	.global ?f258@_QIThunk@ATL@@UEAAJXZ
	.proc	?f258@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f258@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=258*8,r14	// r14 = &m_pUnk->vtbl[258] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[258]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[258].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[258].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f258@_QIThunk@ATL@@UEAAJXZ


	.global ?f259@_QIThunk@ATL@@UEAAJXZ
	.proc	?f259@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f259@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=259*8,r14	// r14 = &m_pUnk->vtbl[259] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[259]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[259].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[259].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f259@_QIThunk@ATL@@UEAAJXZ


	.global ?f260@_QIThunk@ATL@@UEAAJXZ
	.proc	?f260@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f260@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=260*8,r14	// r14 = &m_pUnk->vtbl[260] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[260]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[260].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[260].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f260@_QIThunk@ATL@@UEAAJXZ


	.global ?f261@_QIThunk@ATL@@UEAAJXZ
	.proc	?f261@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f261@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=261*8,r14	// r14 = &m_pUnk->vtbl[261] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[261]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[261].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[261].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f261@_QIThunk@ATL@@UEAAJXZ


	.global ?f262@_QIThunk@ATL@@UEAAJXZ
	.proc	?f262@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f262@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=262*8,r14	// r14 = &m_pUnk->vtbl[262] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[262]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[262].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[262].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f262@_QIThunk@ATL@@UEAAJXZ


	.global ?f263@_QIThunk@ATL@@UEAAJXZ
	.proc	?f263@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f263@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=263*8,r14	// r14 = &m_pUnk->vtbl[263] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[263]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[263].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[263].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f263@_QIThunk@ATL@@UEAAJXZ


	.global ?f264@_QIThunk@ATL@@UEAAJXZ
	.proc	?f264@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f264@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=264*8,r14	// r14 = &m_pUnk->vtbl[264] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[264]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[264].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[264].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f264@_QIThunk@ATL@@UEAAJXZ


	.global ?f265@_QIThunk@ATL@@UEAAJXZ
	.proc	?f265@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f265@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=265*8,r14	// r14 = &m_pUnk->vtbl[265] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[265]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[265].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[265].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f265@_QIThunk@ATL@@UEAAJXZ


	.global ?f266@_QIThunk@ATL@@UEAAJXZ
	.proc	?f266@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f266@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=266*8,r14	// r14 = &m_pUnk->vtbl[266] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[266]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[266].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[266].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f266@_QIThunk@ATL@@UEAAJXZ


	.global ?f267@_QIThunk@ATL@@UEAAJXZ
	.proc	?f267@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f267@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=267*8,r14	// r14 = &m_pUnk->vtbl[267] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[267]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[267].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[267].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f267@_QIThunk@ATL@@UEAAJXZ


	.global ?f268@_QIThunk@ATL@@UEAAJXZ
	.proc	?f268@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f268@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=268*8,r14	// r14 = &m_pUnk->vtbl[268] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[268]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[268].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[268].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f268@_QIThunk@ATL@@UEAAJXZ


	.global ?f269@_QIThunk@ATL@@UEAAJXZ
	.proc	?f269@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f269@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=269*8,r14	// r14 = &m_pUnk->vtbl[269] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[269]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[269].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[269].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f269@_QIThunk@ATL@@UEAAJXZ


	.global ?f270@_QIThunk@ATL@@UEAAJXZ
	.proc	?f270@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f270@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=270*8,r14	// r14 = &m_pUnk->vtbl[270] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[270]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[270].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[270].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f270@_QIThunk@ATL@@UEAAJXZ


	.global ?f271@_QIThunk@ATL@@UEAAJXZ
	.proc	?f271@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f271@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=271*8,r14	// r14 = &m_pUnk->vtbl[271] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[271]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[271].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[271].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f271@_QIThunk@ATL@@UEAAJXZ


	.global ?f272@_QIThunk@ATL@@UEAAJXZ
	.proc	?f272@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f272@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=272*8,r14	// r14 = &m_pUnk->vtbl[272] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[272]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[272].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[272].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f272@_QIThunk@ATL@@UEAAJXZ


	.global ?f273@_QIThunk@ATL@@UEAAJXZ
	.proc	?f273@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f273@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=273*8,r14	// r14 = &m_pUnk->vtbl[273] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[273]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[273].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[273].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f273@_QIThunk@ATL@@UEAAJXZ


	.global ?f274@_QIThunk@ATL@@UEAAJXZ
	.proc	?f274@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f274@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=274*8,r14	// r14 = &m_pUnk->vtbl[274] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[274]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[274].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[274].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f274@_QIThunk@ATL@@UEAAJXZ


	.global ?f275@_QIThunk@ATL@@UEAAJXZ
	.proc	?f275@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f275@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=275*8,r14	// r14 = &m_pUnk->vtbl[275] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[275]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[275].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[275].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f275@_QIThunk@ATL@@UEAAJXZ


	.global ?f276@_QIThunk@ATL@@UEAAJXZ
	.proc	?f276@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f276@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=276*8,r14	// r14 = &m_pUnk->vtbl[276] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[276]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[276].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[276].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f276@_QIThunk@ATL@@UEAAJXZ


	.global ?f277@_QIThunk@ATL@@UEAAJXZ
	.proc	?f277@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f277@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=277*8,r14	// r14 = &m_pUnk->vtbl[277] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[277]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[277].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[277].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f277@_QIThunk@ATL@@UEAAJXZ


	.global ?f278@_QIThunk@ATL@@UEAAJXZ
	.proc	?f278@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f278@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=278*8,r14	// r14 = &m_pUnk->vtbl[278] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[278]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[278].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[278].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f278@_QIThunk@ATL@@UEAAJXZ


	.global ?f279@_QIThunk@ATL@@UEAAJXZ
	.proc	?f279@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f279@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=279*8,r14	// r14 = &m_pUnk->vtbl[279] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[279]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[279].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[279].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f279@_QIThunk@ATL@@UEAAJXZ


	.global ?f280@_QIThunk@ATL@@UEAAJXZ
	.proc	?f280@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f280@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=280*8,r14	// r14 = &m_pUnk->vtbl[280] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[280]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[280].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[280].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f280@_QIThunk@ATL@@UEAAJXZ


	.global ?f281@_QIThunk@ATL@@UEAAJXZ
	.proc	?f281@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f281@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=281*8,r14	// r14 = &m_pUnk->vtbl[281] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[281]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[281].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[281].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f281@_QIThunk@ATL@@UEAAJXZ


	.global ?f282@_QIThunk@ATL@@UEAAJXZ
	.proc	?f282@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f282@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=282*8,r14	// r14 = &m_pUnk->vtbl[282] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[282]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[282].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[282].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f282@_QIThunk@ATL@@UEAAJXZ


	.global ?f283@_QIThunk@ATL@@UEAAJXZ
	.proc	?f283@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f283@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=283*8,r14	// r14 = &m_pUnk->vtbl[283] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[283]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[283].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[283].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f283@_QIThunk@ATL@@UEAAJXZ


	.global ?f284@_QIThunk@ATL@@UEAAJXZ
	.proc	?f284@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f284@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=284*8,r14	// r14 = &m_pUnk->vtbl[284] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[284]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[284].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[284].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f284@_QIThunk@ATL@@UEAAJXZ


	.global ?f285@_QIThunk@ATL@@UEAAJXZ
	.proc	?f285@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f285@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=285*8,r14	// r14 = &m_pUnk->vtbl[285] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[285]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[285].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[285].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f285@_QIThunk@ATL@@UEAAJXZ


	.global ?f286@_QIThunk@ATL@@UEAAJXZ
	.proc	?f286@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f286@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=286*8,r14	// r14 = &m_pUnk->vtbl[286] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[286]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[286].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[286].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f286@_QIThunk@ATL@@UEAAJXZ


	.global ?f287@_QIThunk@ATL@@UEAAJXZ
	.proc	?f287@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f287@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=287*8,r14	// r14 = &m_pUnk->vtbl[287] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[287]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[287].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[287].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f287@_QIThunk@ATL@@UEAAJXZ


	.global ?f288@_QIThunk@ATL@@UEAAJXZ
	.proc	?f288@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f288@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=288*8,r14	// r14 = &m_pUnk->vtbl[288] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[288]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[288].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[288].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f288@_QIThunk@ATL@@UEAAJXZ


	.global ?f289@_QIThunk@ATL@@UEAAJXZ
	.proc	?f289@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f289@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=289*8,r14	// r14 = &m_pUnk->vtbl[289] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[289]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[289].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[289].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f289@_QIThunk@ATL@@UEAAJXZ


	.global ?f290@_QIThunk@ATL@@UEAAJXZ
	.proc	?f290@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f290@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=290*8,r14	// r14 = &m_pUnk->vtbl[290] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[290]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[290].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[290].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f290@_QIThunk@ATL@@UEAAJXZ


	.global ?f291@_QIThunk@ATL@@UEAAJXZ
	.proc	?f291@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f291@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=291*8,r14	// r14 = &m_pUnk->vtbl[291] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[291]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[291].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[291].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f291@_QIThunk@ATL@@UEAAJXZ


	.global ?f292@_QIThunk@ATL@@UEAAJXZ
	.proc	?f292@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f292@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=292*8,r14	// r14 = &m_pUnk->vtbl[292] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[292]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[292].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[292].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f292@_QIThunk@ATL@@UEAAJXZ


	.global ?f293@_QIThunk@ATL@@UEAAJXZ
	.proc	?f293@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f293@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=293*8,r14	// r14 = &m_pUnk->vtbl[293] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[293]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[293].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[293].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f293@_QIThunk@ATL@@UEAAJXZ


	.global ?f294@_QIThunk@ATL@@UEAAJXZ
	.proc	?f294@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f294@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=294*8,r14	// r14 = &m_pUnk->vtbl[294] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[294]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[294].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[294].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f294@_QIThunk@ATL@@UEAAJXZ


	.global ?f295@_QIThunk@ATL@@UEAAJXZ
	.proc	?f295@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f295@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=295*8,r14	// r14 = &m_pUnk->vtbl[295] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[295]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[295].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[295].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f295@_QIThunk@ATL@@UEAAJXZ


	.global ?f296@_QIThunk@ATL@@UEAAJXZ
	.proc	?f296@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f296@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=296*8,r14	// r14 = &m_pUnk->vtbl[296] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[296]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[296].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[296].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f296@_QIThunk@ATL@@UEAAJXZ


	.global ?f297@_QIThunk@ATL@@UEAAJXZ
	.proc	?f297@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f297@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=297*8,r14	// r14 = &m_pUnk->vtbl[297] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[297]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[297].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[297].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f297@_QIThunk@ATL@@UEAAJXZ


	.global ?f298@_QIThunk@ATL@@UEAAJXZ
	.proc	?f298@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f298@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=298*8,r14	// r14 = &m_pUnk->vtbl[298] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[298]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[298].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[298].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f298@_QIThunk@ATL@@UEAAJXZ


	.global ?f299@_QIThunk@ATL@@UEAAJXZ
	.proc	?f299@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f299@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=299*8,r14	// r14 = &m_pUnk->vtbl[299] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[299]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[299].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[299].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f299@_QIThunk@ATL@@UEAAJXZ


	.global ?f300@_QIThunk@ATL@@UEAAJXZ
	.proc	?f300@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f300@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=300*8,r14	// r14 = &m_pUnk->vtbl[300] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[300]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[300].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[300].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f300@_QIThunk@ATL@@UEAAJXZ


	.global ?f301@_QIThunk@ATL@@UEAAJXZ
	.proc	?f301@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f301@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=301*8,r14	// r14 = &m_pUnk->vtbl[301] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[301]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[301].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[301].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f301@_QIThunk@ATL@@UEAAJXZ


	.global ?f302@_QIThunk@ATL@@UEAAJXZ
	.proc	?f302@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f302@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=302*8,r14	// r14 = &m_pUnk->vtbl[302] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[302]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[302].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[302].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f302@_QIThunk@ATL@@UEAAJXZ


	.global ?f303@_QIThunk@ATL@@UEAAJXZ
	.proc	?f303@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f303@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=303*8,r14	// r14 = &m_pUnk->vtbl[303] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[303]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[303].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[303].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f303@_QIThunk@ATL@@UEAAJXZ


	.global ?f304@_QIThunk@ATL@@UEAAJXZ
	.proc	?f304@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f304@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=304*8,r14	// r14 = &m_pUnk->vtbl[304] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[304]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[304].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[304].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f304@_QIThunk@ATL@@UEAAJXZ


	.global ?f305@_QIThunk@ATL@@UEAAJXZ
	.proc	?f305@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f305@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=305*8,r14	// r14 = &m_pUnk->vtbl[305] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[305]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[305].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[305].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f305@_QIThunk@ATL@@UEAAJXZ


	.global ?f306@_QIThunk@ATL@@UEAAJXZ
	.proc	?f306@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f306@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=306*8,r14	// r14 = &m_pUnk->vtbl[306] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[306]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[306].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[306].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f306@_QIThunk@ATL@@UEAAJXZ


	.global ?f307@_QIThunk@ATL@@UEAAJXZ
	.proc	?f307@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f307@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=307*8,r14	// r14 = &m_pUnk->vtbl[307] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[307]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[307].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[307].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f307@_QIThunk@ATL@@UEAAJXZ


	.global ?f308@_QIThunk@ATL@@UEAAJXZ
	.proc	?f308@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f308@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=308*8,r14	// r14 = &m_pUnk->vtbl[308] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[308]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[308].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[308].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f308@_QIThunk@ATL@@UEAAJXZ


	.global ?f309@_QIThunk@ATL@@UEAAJXZ
	.proc	?f309@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f309@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=309*8,r14	// r14 = &m_pUnk->vtbl[309] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[309]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[309].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[309].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f309@_QIThunk@ATL@@UEAAJXZ


	.global ?f310@_QIThunk@ATL@@UEAAJXZ
	.proc	?f310@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f310@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=310*8,r14	// r14 = &m_pUnk->vtbl[310] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[310]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[310].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[310].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f310@_QIThunk@ATL@@UEAAJXZ


	.global ?f311@_QIThunk@ATL@@UEAAJXZ
	.proc	?f311@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f311@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=311*8,r14	// r14 = &m_pUnk->vtbl[311] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[311]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[311].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[311].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f311@_QIThunk@ATL@@UEAAJXZ


	.global ?f312@_QIThunk@ATL@@UEAAJXZ
	.proc	?f312@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f312@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=312*8,r14	// r14 = &m_pUnk->vtbl[312] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[312]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[312].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[312].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f312@_QIThunk@ATL@@UEAAJXZ


	.global ?f313@_QIThunk@ATL@@UEAAJXZ
	.proc	?f313@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f313@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=313*8,r14	// r14 = &m_pUnk->vtbl[313] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[313]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[313].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[313].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f313@_QIThunk@ATL@@UEAAJXZ


	.global ?f314@_QIThunk@ATL@@UEAAJXZ
	.proc	?f314@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f314@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=314*8,r14	// r14 = &m_pUnk->vtbl[314] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[314]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[314].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[314].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f314@_QIThunk@ATL@@UEAAJXZ


	.global ?f315@_QIThunk@ATL@@UEAAJXZ
	.proc	?f315@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f315@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=315*8,r14	// r14 = &m_pUnk->vtbl[315] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[315]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[315].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[315].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f315@_QIThunk@ATL@@UEAAJXZ


	.global ?f316@_QIThunk@ATL@@UEAAJXZ
	.proc	?f316@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f316@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=316*8,r14	// r14 = &m_pUnk->vtbl[316] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[316]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[316].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[316].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f316@_QIThunk@ATL@@UEAAJXZ


	.global ?f317@_QIThunk@ATL@@UEAAJXZ
	.proc	?f317@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f317@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=317*8,r14	// r14 = &m_pUnk->vtbl[317] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[317]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[317].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[317].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f317@_QIThunk@ATL@@UEAAJXZ


	.global ?f318@_QIThunk@ATL@@UEAAJXZ
	.proc	?f318@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f318@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=318*8,r14	// r14 = &m_pUnk->vtbl[318] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[318]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[318].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[318].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f318@_QIThunk@ATL@@UEAAJXZ


	.global ?f319@_QIThunk@ATL@@UEAAJXZ
	.proc	?f319@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f319@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=319*8,r14	// r14 = &m_pUnk->vtbl[319] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[319]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[319].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[319].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f319@_QIThunk@ATL@@UEAAJXZ


	.global ?f320@_QIThunk@ATL@@UEAAJXZ
	.proc	?f320@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f320@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=320*8,r14	// r14 = &m_pUnk->vtbl[320] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[320]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[320].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[320].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f320@_QIThunk@ATL@@UEAAJXZ


	.global ?f321@_QIThunk@ATL@@UEAAJXZ
	.proc	?f321@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f321@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=321*8,r14	// r14 = &m_pUnk->vtbl[321] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[321]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[321].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[321].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f321@_QIThunk@ATL@@UEAAJXZ


	.global ?f322@_QIThunk@ATL@@UEAAJXZ
	.proc	?f322@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f322@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=322*8,r14	// r14 = &m_pUnk->vtbl[322] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[322]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[322].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[322].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f322@_QIThunk@ATL@@UEAAJXZ


	.global ?f323@_QIThunk@ATL@@UEAAJXZ
	.proc	?f323@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f323@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=323*8,r14	// r14 = &m_pUnk->vtbl[323] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[323]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[323].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[323].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f323@_QIThunk@ATL@@UEAAJXZ


	.global ?f324@_QIThunk@ATL@@UEAAJXZ
	.proc	?f324@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f324@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=324*8,r14	// r14 = &m_pUnk->vtbl[324] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[324]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[324].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[324].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f324@_QIThunk@ATL@@UEAAJXZ


	.global ?f325@_QIThunk@ATL@@UEAAJXZ
	.proc	?f325@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f325@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=325*8,r14	// r14 = &m_pUnk->vtbl[325] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[325]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[325].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[325].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f325@_QIThunk@ATL@@UEAAJXZ


	.global ?f326@_QIThunk@ATL@@UEAAJXZ
	.proc	?f326@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f326@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=326*8,r14	// r14 = &m_pUnk->vtbl[326] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[326]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[326].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[326].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f326@_QIThunk@ATL@@UEAAJXZ


	.global ?f327@_QIThunk@ATL@@UEAAJXZ
	.proc	?f327@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f327@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=327*8,r14	// r14 = &m_pUnk->vtbl[327] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[327]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[327].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[327].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f327@_QIThunk@ATL@@UEAAJXZ


	.global ?f328@_QIThunk@ATL@@UEAAJXZ
	.proc	?f328@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f328@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=328*8,r14	// r14 = &m_pUnk->vtbl[328] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[328]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[328].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[328].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f328@_QIThunk@ATL@@UEAAJXZ


	.global ?f329@_QIThunk@ATL@@UEAAJXZ
	.proc	?f329@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f329@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=329*8,r14	// r14 = &m_pUnk->vtbl[329] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[329]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[329].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[329].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f329@_QIThunk@ATL@@UEAAJXZ


	.global ?f330@_QIThunk@ATL@@UEAAJXZ
	.proc	?f330@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f330@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=330*8,r14	// r14 = &m_pUnk->vtbl[330] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[330]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[330].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[330].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f330@_QIThunk@ATL@@UEAAJXZ


	.global ?f331@_QIThunk@ATL@@UEAAJXZ
	.proc	?f331@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f331@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=331*8,r14	// r14 = &m_pUnk->vtbl[331] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[331]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[331].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[331].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f331@_QIThunk@ATL@@UEAAJXZ


	.global ?f332@_QIThunk@ATL@@UEAAJXZ
	.proc	?f332@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f332@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=332*8,r14	// r14 = &m_pUnk->vtbl[332] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[332]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[332].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[332].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f332@_QIThunk@ATL@@UEAAJXZ


	.global ?f333@_QIThunk@ATL@@UEAAJXZ
	.proc	?f333@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f333@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=333*8,r14	// r14 = &m_pUnk->vtbl[333] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[333]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[333].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[333].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f333@_QIThunk@ATL@@UEAAJXZ


	.global ?f334@_QIThunk@ATL@@UEAAJXZ
	.proc	?f334@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f334@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=334*8,r14	// r14 = &m_pUnk->vtbl[334] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[334]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[334].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[334].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f334@_QIThunk@ATL@@UEAAJXZ


	.global ?f335@_QIThunk@ATL@@UEAAJXZ
	.proc	?f335@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f335@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=335*8,r14	// r14 = &m_pUnk->vtbl[335] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[335]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[335].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[335].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f335@_QIThunk@ATL@@UEAAJXZ


	.global ?f336@_QIThunk@ATL@@UEAAJXZ
	.proc	?f336@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f336@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=336*8,r14	// r14 = &m_pUnk->vtbl[336] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[336]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[336].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[336].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f336@_QIThunk@ATL@@UEAAJXZ


	.global ?f337@_QIThunk@ATL@@UEAAJXZ
	.proc	?f337@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f337@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=337*8,r14	// r14 = &m_pUnk->vtbl[337] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[337]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[337].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[337].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f337@_QIThunk@ATL@@UEAAJXZ


	.global ?f338@_QIThunk@ATL@@UEAAJXZ
	.proc	?f338@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f338@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=338*8,r14	// r14 = &m_pUnk->vtbl[338] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[338]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[338].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[338].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f338@_QIThunk@ATL@@UEAAJXZ


	.global ?f339@_QIThunk@ATL@@UEAAJXZ
	.proc	?f339@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f339@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=339*8,r14	// r14 = &m_pUnk->vtbl[339] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[339]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[339].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[339].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f339@_QIThunk@ATL@@UEAAJXZ


	.global ?f340@_QIThunk@ATL@@UEAAJXZ
	.proc	?f340@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f340@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=340*8,r14	// r14 = &m_pUnk->vtbl[340] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[340]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[340].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[340].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f340@_QIThunk@ATL@@UEAAJXZ


	.global ?f341@_QIThunk@ATL@@UEAAJXZ
	.proc	?f341@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f341@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=341*8,r14	// r14 = &m_pUnk->vtbl[341] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[341]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[341].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[341].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f341@_QIThunk@ATL@@UEAAJXZ


	.global ?f342@_QIThunk@ATL@@UEAAJXZ
	.proc	?f342@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f342@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=342*8,r14	// r14 = &m_pUnk->vtbl[342] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[342]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[342].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[342].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f342@_QIThunk@ATL@@UEAAJXZ


	.global ?f343@_QIThunk@ATL@@UEAAJXZ
	.proc	?f343@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f343@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=343*8,r14	// r14 = &m_pUnk->vtbl[343] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[343]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[343].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[343].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f343@_QIThunk@ATL@@UEAAJXZ


	.global ?f344@_QIThunk@ATL@@UEAAJXZ
	.proc	?f344@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f344@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=344*8,r14	// r14 = &m_pUnk->vtbl[344] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[344]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[344].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[344].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f344@_QIThunk@ATL@@UEAAJXZ


	.global ?f345@_QIThunk@ATL@@UEAAJXZ
	.proc	?f345@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f345@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=345*8,r14	// r14 = &m_pUnk->vtbl[345] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[345]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[345].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[345].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f345@_QIThunk@ATL@@UEAAJXZ


	.global ?f346@_QIThunk@ATL@@UEAAJXZ
	.proc	?f346@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f346@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=346*8,r14	// r14 = &m_pUnk->vtbl[346] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[346]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[346].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[346].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f346@_QIThunk@ATL@@UEAAJXZ


	.global ?f347@_QIThunk@ATL@@UEAAJXZ
	.proc	?f347@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f347@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=347*8,r14	// r14 = &m_pUnk->vtbl[347] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[347]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[347].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[347].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f347@_QIThunk@ATL@@UEAAJXZ


	.global ?f348@_QIThunk@ATL@@UEAAJXZ
	.proc	?f348@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f348@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=348*8,r14	// r14 = &m_pUnk->vtbl[348] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[348]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[348].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[348].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f348@_QIThunk@ATL@@UEAAJXZ


	.global ?f349@_QIThunk@ATL@@UEAAJXZ
	.proc	?f349@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f349@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=349*8,r14	// r14 = &m_pUnk->vtbl[349] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[349]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[349].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[349].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f349@_QIThunk@ATL@@UEAAJXZ


	.global ?f350@_QIThunk@ATL@@UEAAJXZ
	.proc	?f350@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f350@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=350*8,r14	// r14 = &m_pUnk->vtbl[350] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[350]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[350].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[350].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f350@_QIThunk@ATL@@UEAAJXZ


	.global ?f351@_QIThunk@ATL@@UEAAJXZ
	.proc	?f351@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f351@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=351*8,r14	// r14 = &m_pUnk->vtbl[351] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[351]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[351].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[351].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f351@_QIThunk@ATL@@UEAAJXZ


	.global ?f352@_QIThunk@ATL@@UEAAJXZ
	.proc	?f352@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f352@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=352*8,r14	// r14 = &m_pUnk->vtbl[352] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[352]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[352].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[352].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f352@_QIThunk@ATL@@UEAAJXZ


	.global ?f353@_QIThunk@ATL@@UEAAJXZ
	.proc	?f353@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f353@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=353*8,r14	// r14 = &m_pUnk->vtbl[353] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[353]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[353].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[353].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f353@_QIThunk@ATL@@UEAAJXZ


	.global ?f354@_QIThunk@ATL@@UEAAJXZ
	.proc	?f354@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f354@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=354*8,r14	// r14 = &m_pUnk->vtbl[354] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[354]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[354].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[354].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f354@_QIThunk@ATL@@UEAAJXZ


	.global ?f355@_QIThunk@ATL@@UEAAJXZ
	.proc	?f355@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f355@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=355*8,r14	// r14 = &m_pUnk->vtbl[355] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[355]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[355].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[355].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f355@_QIThunk@ATL@@UEAAJXZ


	.global ?f356@_QIThunk@ATL@@UEAAJXZ
	.proc	?f356@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f356@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=356*8,r14	// r14 = &m_pUnk->vtbl[356] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[356]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[356].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[356].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f356@_QIThunk@ATL@@UEAAJXZ


	.global ?f357@_QIThunk@ATL@@UEAAJXZ
	.proc	?f357@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f357@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=357*8,r14	// r14 = &m_pUnk->vtbl[357] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[357]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[357].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[357].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f357@_QIThunk@ATL@@UEAAJXZ


	.global ?f358@_QIThunk@ATL@@UEAAJXZ
	.proc	?f358@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f358@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=358*8,r14	// r14 = &m_pUnk->vtbl[358] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[358]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[358].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[358].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f358@_QIThunk@ATL@@UEAAJXZ


	.global ?f359@_QIThunk@ATL@@UEAAJXZ
	.proc	?f359@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f359@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=359*8,r14	// r14 = &m_pUnk->vtbl[359] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[359]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[359].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[359].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f359@_QIThunk@ATL@@UEAAJXZ


	.global ?f360@_QIThunk@ATL@@UEAAJXZ
	.proc	?f360@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f360@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=360*8,r14	// r14 = &m_pUnk->vtbl[360] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[360]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[360].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[360].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f360@_QIThunk@ATL@@UEAAJXZ


	.global ?f361@_QIThunk@ATL@@UEAAJXZ
	.proc	?f361@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f361@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=361*8,r14	// r14 = &m_pUnk->vtbl[361] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[361]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[361].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[361].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f361@_QIThunk@ATL@@UEAAJXZ


	.global ?f362@_QIThunk@ATL@@UEAAJXZ
	.proc	?f362@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f362@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=362*8,r14	// r14 = &m_pUnk->vtbl[362] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[362]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[362].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[362].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f362@_QIThunk@ATL@@UEAAJXZ


	.global ?f363@_QIThunk@ATL@@UEAAJXZ
	.proc	?f363@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f363@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=363*8,r14	// r14 = &m_pUnk->vtbl[363] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[363]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[363].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[363].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f363@_QIThunk@ATL@@UEAAJXZ


	.global ?f364@_QIThunk@ATL@@UEAAJXZ
	.proc	?f364@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f364@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=364*8,r14	// r14 = &m_pUnk->vtbl[364] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[364]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[364].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[364].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f364@_QIThunk@ATL@@UEAAJXZ


	.global ?f365@_QIThunk@ATL@@UEAAJXZ
	.proc	?f365@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f365@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=365*8,r14	// r14 = &m_pUnk->vtbl[365] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[365]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[365].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[365].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f365@_QIThunk@ATL@@UEAAJXZ


	.global ?f366@_QIThunk@ATL@@UEAAJXZ
	.proc	?f366@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f366@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=366*8,r14	// r14 = &m_pUnk->vtbl[366] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[366]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[366].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[366].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f366@_QIThunk@ATL@@UEAAJXZ


	.global ?f367@_QIThunk@ATL@@UEAAJXZ
	.proc	?f367@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f367@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=367*8,r14	// r14 = &m_pUnk->vtbl[367] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[367]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[367].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[367].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f367@_QIThunk@ATL@@UEAAJXZ


	.global ?f368@_QIThunk@ATL@@UEAAJXZ
	.proc	?f368@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f368@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=368*8,r14	// r14 = &m_pUnk->vtbl[368] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[368]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[368].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[368].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f368@_QIThunk@ATL@@UEAAJXZ


	.global ?f369@_QIThunk@ATL@@UEAAJXZ
	.proc	?f369@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f369@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=369*8,r14	// r14 = &m_pUnk->vtbl[369] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[369]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[369].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[369].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f369@_QIThunk@ATL@@UEAAJXZ


	.global ?f370@_QIThunk@ATL@@UEAAJXZ
	.proc	?f370@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f370@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=370*8,r14	// r14 = &m_pUnk->vtbl[370] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[370]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[370].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[370].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f370@_QIThunk@ATL@@UEAAJXZ


	.global ?f371@_QIThunk@ATL@@UEAAJXZ
	.proc	?f371@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f371@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=371*8,r14	// r14 = &m_pUnk->vtbl[371] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[371]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[371].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[371].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f371@_QIThunk@ATL@@UEAAJXZ


	.global ?f372@_QIThunk@ATL@@UEAAJXZ
	.proc	?f372@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f372@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=372*8,r14	// r14 = &m_pUnk->vtbl[372] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[372]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[372].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[372].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f372@_QIThunk@ATL@@UEAAJXZ


	.global ?f373@_QIThunk@ATL@@UEAAJXZ
	.proc	?f373@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f373@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=373*8,r14	// r14 = &m_pUnk->vtbl[373] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[373]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[373].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[373].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f373@_QIThunk@ATL@@UEAAJXZ


	.global ?f374@_QIThunk@ATL@@UEAAJXZ
	.proc	?f374@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f374@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=374*8,r14	// r14 = &m_pUnk->vtbl[374] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[374]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[374].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[374].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f374@_QIThunk@ATL@@UEAAJXZ


	.global ?f375@_QIThunk@ATL@@UEAAJXZ
	.proc	?f375@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f375@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=375*8,r14	// r14 = &m_pUnk->vtbl[375] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[375]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[375].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[375].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f375@_QIThunk@ATL@@UEAAJXZ


	.global ?f376@_QIThunk@ATL@@UEAAJXZ
	.proc	?f376@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f376@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=376*8,r14	// r14 = &m_pUnk->vtbl[376] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[376]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[376].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[376].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f376@_QIThunk@ATL@@UEAAJXZ


	.global ?f377@_QIThunk@ATL@@UEAAJXZ
	.proc	?f377@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f377@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=377*8,r14	// r14 = &m_pUnk->vtbl[377] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[377]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[377].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[377].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f377@_QIThunk@ATL@@UEAAJXZ


	.global ?f378@_QIThunk@ATL@@UEAAJXZ
	.proc	?f378@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f378@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=378*8,r14	// r14 = &m_pUnk->vtbl[378] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[378]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[378].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[378].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f378@_QIThunk@ATL@@UEAAJXZ


	.global ?f379@_QIThunk@ATL@@UEAAJXZ
	.proc	?f379@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f379@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=379*8,r14	// r14 = &m_pUnk->vtbl[379] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[379]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[379].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[379].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f379@_QIThunk@ATL@@UEAAJXZ


	.global ?f380@_QIThunk@ATL@@UEAAJXZ
	.proc	?f380@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f380@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=380*8,r14	// r14 = &m_pUnk->vtbl[380] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[380]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[380].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[380].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f380@_QIThunk@ATL@@UEAAJXZ


	.global ?f381@_QIThunk@ATL@@UEAAJXZ
	.proc	?f381@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f381@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=381*8,r14	// r14 = &m_pUnk->vtbl[381] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[381]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[381].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[381].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f381@_QIThunk@ATL@@UEAAJXZ


	.global ?f382@_QIThunk@ATL@@UEAAJXZ
	.proc	?f382@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f382@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=382*8,r14	// r14 = &m_pUnk->vtbl[382] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[382]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[382].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[382].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f382@_QIThunk@ATL@@UEAAJXZ


	.global ?f383@_QIThunk@ATL@@UEAAJXZ
	.proc	?f383@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f383@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=383*8,r14	// r14 = &m_pUnk->vtbl[383] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[383]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[383].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[383].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f383@_QIThunk@ATL@@UEAAJXZ


	.global ?f384@_QIThunk@ATL@@UEAAJXZ
	.proc	?f384@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f384@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=384*8,r14	// r14 = &m_pUnk->vtbl[384] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[384]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[384].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[384].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f384@_QIThunk@ATL@@UEAAJXZ


	.global ?f385@_QIThunk@ATL@@UEAAJXZ
	.proc	?f385@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f385@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=385*8,r14	// r14 = &m_pUnk->vtbl[385] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[385]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[385].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[385].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f385@_QIThunk@ATL@@UEAAJXZ


	.global ?f386@_QIThunk@ATL@@UEAAJXZ
	.proc	?f386@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f386@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=386*8,r14	// r14 = &m_pUnk->vtbl[386] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[386]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[386].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[386].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f386@_QIThunk@ATL@@UEAAJXZ


	.global ?f387@_QIThunk@ATL@@UEAAJXZ
	.proc	?f387@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f387@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=387*8,r14	// r14 = &m_pUnk->vtbl[387] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[387]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[387].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[387].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f387@_QIThunk@ATL@@UEAAJXZ


	.global ?f388@_QIThunk@ATL@@UEAAJXZ
	.proc	?f388@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f388@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=388*8,r14	// r14 = &m_pUnk->vtbl[388] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[388]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[388].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[388].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f388@_QIThunk@ATL@@UEAAJXZ


	.global ?f389@_QIThunk@ATL@@UEAAJXZ
	.proc	?f389@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f389@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=389*8,r14	// r14 = &m_pUnk->vtbl[389] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[389]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[389].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[389].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f389@_QIThunk@ATL@@UEAAJXZ


	.global ?f390@_QIThunk@ATL@@UEAAJXZ
	.proc	?f390@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f390@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=390*8,r14	// r14 = &m_pUnk->vtbl[390] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[390]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[390].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[390].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f390@_QIThunk@ATL@@UEAAJXZ


	.global ?f391@_QIThunk@ATL@@UEAAJXZ
	.proc	?f391@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f391@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=391*8,r14	// r14 = &m_pUnk->vtbl[391] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[391]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[391].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[391].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f391@_QIThunk@ATL@@UEAAJXZ


	.global ?f392@_QIThunk@ATL@@UEAAJXZ
	.proc	?f392@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f392@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=392*8,r14	// r14 = &m_pUnk->vtbl[392] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[392]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[392].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[392].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f392@_QIThunk@ATL@@UEAAJXZ


	.global ?f393@_QIThunk@ATL@@UEAAJXZ
	.proc	?f393@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f393@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=393*8,r14	// r14 = &m_pUnk->vtbl[393] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[393]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[393].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[393].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f393@_QIThunk@ATL@@UEAAJXZ


	.global ?f394@_QIThunk@ATL@@UEAAJXZ
	.proc	?f394@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f394@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=394*8,r14	// r14 = &m_pUnk->vtbl[394] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[394]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[394].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[394].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f394@_QIThunk@ATL@@UEAAJXZ


	.global ?f395@_QIThunk@ATL@@UEAAJXZ
	.proc	?f395@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f395@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=395*8,r14	// r14 = &m_pUnk->vtbl[395] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[395]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[395].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[395].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f395@_QIThunk@ATL@@UEAAJXZ


	.global ?f396@_QIThunk@ATL@@UEAAJXZ
	.proc	?f396@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f396@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=396*8,r14	// r14 = &m_pUnk->vtbl[396] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[396]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[396].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[396].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f396@_QIThunk@ATL@@UEAAJXZ


	.global ?f397@_QIThunk@ATL@@UEAAJXZ
	.proc	?f397@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f397@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=397*8,r14	// r14 = &m_pUnk->vtbl[397] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[397]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[397].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[397].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f397@_QIThunk@ATL@@UEAAJXZ


	.global ?f398@_QIThunk@ATL@@UEAAJXZ
	.proc	?f398@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f398@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=398*8,r14	// r14 = &m_pUnk->vtbl[398] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[398]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[398].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[398].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f398@_QIThunk@ATL@@UEAAJXZ


	.global ?f399@_QIThunk@ATL@@UEAAJXZ
	.proc	?f399@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f399@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=399*8,r14	// r14 = &m_pUnk->vtbl[399] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[399]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[399].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[399].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f399@_QIThunk@ATL@@UEAAJXZ


	.global ?f400@_QIThunk@ATL@@UEAAJXZ
	.proc	?f400@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f400@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=400*8,r14	// r14 = &m_pUnk->vtbl[400] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[400]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[400].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[400].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f400@_QIThunk@ATL@@UEAAJXZ


	.global ?f401@_QIThunk@ATL@@UEAAJXZ
	.proc	?f401@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f401@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=401*8,r14	// r14 = &m_pUnk->vtbl[401] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[401]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[401].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[401].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f401@_QIThunk@ATL@@UEAAJXZ


	.global ?f402@_QIThunk@ATL@@UEAAJXZ
	.proc	?f402@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f402@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=402*8,r14	// r14 = &m_pUnk->vtbl[402] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[402]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[402].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[402].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f402@_QIThunk@ATL@@UEAAJXZ


	.global ?f403@_QIThunk@ATL@@UEAAJXZ
	.proc	?f403@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f403@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=403*8,r14	// r14 = &m_pUnk->vtbl[403] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[403]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[403].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[403].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f403@_QIThunk@ATL@@UEAAJXZ


	.global ?f404@_QIThunk@ATL@@UEAAJXZ
	.proc	?f404@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f404@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=404*8,r14	// r14 = &m_pUnk->vtbl[404] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[404]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[404].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[404].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f404@_QIThunk@ATL@@UEAAJXZ


	.global ?f405@_QIThunk@ATL@@UEAAJXZ
	.proc	?f405@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f405@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=405*8,r14	// r14 = &m_pUnk->vtbl[405] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[405]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[405].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[405].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f405@_QIThunk@ATL@@UEAAJXZ


	.global ?f406@_QIThunk@ATL@@UEAAJXZ
	.proc	?f406@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f406@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=406*8,r14	// r14 = &m_pUnk->vtbl[406] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[406]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[406].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[406].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f406@_QIThunk@ATL@@UEAAJXZ


	.global ?f407@_QIThunk@ATL@@UEAAJXZ
	.proc	?f407@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f407@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=407*8,r14	// r14 = &m_pUnk->vtbl[407] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[407]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[407].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[407].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f407@_QIThunk@ATL@@UEAAJXZ


	.global ?f408@_QIThunk@ATL@@UEAAJXZ
	.proc	?f408@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f408@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=408*8,r14	// r14 = &m_pUnk->vtbl[408] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[408]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[408].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[408].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f408@_QIThunk@ATL@@UEAAJXZ


	.global ?f409@_QIThunk@ATL@@UEAAJXZ
	.proc	?f409@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f409@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=409*8,r14	// r14 = &m_pUnk->vtbl[409] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[409]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[409].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[409].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f409@_QIThunk@ATL@@UEAAJXZ


	.global ?f410@_QIThunk@ATL@@UEAAJXZ
	.proc	?f410@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f410@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=410*8,r14	// r14 = &m_pUnk->vtbl[410] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[410]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[410].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[410].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f410@_QIThunk@ATL@@UEAAJXZ


	.global ?f411@_QIThunk@ATL@@UEAAJXZ
	.proc	?f411@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f411@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=411*8,r14	// r14 = &m_pUnk->vtbl[411] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[411]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[411].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[411].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f411@_QIThunk@ATL@@UEAAJXZ


	.global ?f412@_QIThunk@ATL@@UEAAJXZ
	.proc	?f412@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f412@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=412*8,r14	// r14 = &m_pUnk->vtbl[412] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[412]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[412].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[412].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f412@_QIThunk@ATL@@UEAAJXZ


	.global ?f413@_QIThunk@ATL@@UEAAJXZ
	.proc	?f413@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f413@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=413*8,r14	// r14 = &m_pUnk->vtbl[413] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[413]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[413].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[413].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f413@_QIThunk@ATL@@UEAAJXZ


	.global ?f414@_QIThunk@ATL@@UEAAJXZ
	.proc	?f414@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f414@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=414*8,r14	// r14 = &m_pUnk->vtbl[414] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[414]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[414].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[414].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f414@_QIThunk@ATL@@UEAAJXZ


	.global ?f415@_QIThunk@ATL@@UEAAJXZ
	.proc	?f415@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f415@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=415*8,r14	// r14 = &m_pUnk->vtbl[415] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[415]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[415].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[415].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f415@_QIThunk@ATL@@UEAAJXZ


	.global ?f416@_QIThunk@ATL@@UEAAJXZ
	.proc	?f416@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f416@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=416*8,r14	// r14 = &m_pUnk->vtbl[416] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[416]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[416].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[416].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f416@_QIThunk@ATL@@UEAAJXZ


	.global ?f417@_QIThunk@ATL@@UEAAJXZ
	.proc	?f417@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f417@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=417*8,r14	// r14 = &m_pUnk->vtbl[417] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[417]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[417].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[417].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f417@_QIThunk@ATL@@UEAAJXZ


	.global ?f418@_QIThunk@ATL@@UEAAJXZ
	.proc	?f418@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f418@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=418*8,r14	// r14 = &m_pUnk->vtbl[418] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[418]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[418].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[418].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f418@_QIThunk@ATL@@UEAAJXZ


	.global ?f419@_QIThunk@ATL@@UEAAJXZ
	.proc	?f419@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f419@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=419*8,r14	// r14 = &m_pUnk->vtbl[419] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[419]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[419].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[419].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f419@_QIThunk@ATL@@UEAAJXZ


	.global ?f420@_QIThunk@ATL@@UEAAJXZ
	.proc	?f420@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f420@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=420*8,r14	// r14 = &m_pUnk->vtbl[420] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[420]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[420].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[420].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f420@_QIThunk@ATL@@UEAAJXZ


	.global ?f421@_QIThunk@ATL@@UEAAJXZ
	.proc	?f421@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f421@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=421*8,r14	// r14 = &m_pUnk->vtbl[421] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[421]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[421].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[421].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f421@_QIThunk@ATL@@UEAAJXZ


	.global ?f422@_QIThunk@ATL@@UEAAJXZ
	.proc	?f422@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f422@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=422*8,r14	// r14 = &m_pUnk->vtbl[422] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[422]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[422].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[422].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f422@_QIThunk@ATL@@UEAAJXZ


	.global ?f423@_QIThunk@ATL@@UEAAJXZ
	.proc	?f423@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f423@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=423*8,r14	// r14 = &m_pUnk->vtbl[423] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[423]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[423].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[423].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f423@_QIThunk@ATL@@UEAAJXZ


	.global ?f424@_QIThunk@ATL@@UEAAJXZ
	.proc	?f424@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f424@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=424*8,r14	// r14 = &m_pUnk->vtbl[424] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[424]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[424].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[424].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f424@_QIThunk@ATL@@UEAAJXZ


	.global ?f425@_QIThunk@ATL@@UEAAJXZ
	.proc	?f425@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f425@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=425*8,r14	// r14 = &m_pUnk->vtbl[425] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[425]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[425].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[425].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f425@_QIThunk@ATL@@UEAAJXZ


	.global ?f426@_QIThunk@ATL@@UEAAJXZ
	.proc	?f426@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f426@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=426*8,r14	// r14 = &m_pUnk->vtbl[426] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[426]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[426].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[426].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f426@_QIThunk@ATL@@UEAAJXZ


	.global ?f427@_QIThunk@ATL@@UEAAJXZ
	.proc	?f427@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f427@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=427*8,r14	// r14 = &m_pUnk->vtbl[427] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[427]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[427].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[427].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f427@_QIThunk@ATL@@UEAAJXZ


	.global ?f428@_QIThunk@ATL@@UEAAJXZ
	.proc	?f428@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f428@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=428*8,r14	// r14 = &m_pUnk->vtbl[428] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[428]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[428].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[428].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f428@_QIThunk@ATL@@UEAAJXZ


	.global ?f429@_QIThunk@ATL@@UEAAJXZ
	.proc	?f429@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f429@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=429*8,r14	// r14 = &m_pUnk->vtbl[429] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[429]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[429].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[429].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f429@_QIThunk@ATL@@UEAAJXZ


	.global ?f430@_QIThunk@ATL@@UEAAJXZ
	.proc	?f430@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f430@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=430*8,r14	// r14 = &m_pUnk->vtbl[430] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[430]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[430].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[430].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f430@_QIThunk@ATL@@UEAAJXZ


	.global ?f431@_QIThunk@ATL@@UEAAJXZ
	.proc	?f431@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f431@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=431*8,r14	// r14 = &m_pUnk->vtbl[431] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[431]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[431].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[431].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f431@_QIThunk@ATL@@UEAAJXZ


	.global ?f432@_QIThunk@ATL@@UEAAJXZ
	.proc	?f432@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f432@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=432*8,r14	// r14 = &m_pUnk->vtbl[432] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[432]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[432].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[432].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f432@_QIThunk@ATL@@UEAAJXZ


	.global ?f433@_QIThunk@ATL@@UEAAJXZ
	.proc	?f433@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f433@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=433*8,r14	// r14 = &m_pUnk->vtbl[433] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[433]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[433].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[433].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f433@_QIThunk@ATL@@UEAAJXZ


	.global ?f434@_QIThunk@ATL@@UEAAJXZ
	.proc	?f434@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f434@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=434*8,r14	// r14 = &m_pUnk->vtbl[434] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[434]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[434].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[434].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f434@_QIThunk@ATL@@UEAAJXZ


	.global ?f435@_QIThunk@ATL@@UEAAJXZ
	.proc	?f435@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f435@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=435*8,r14	// r14 = &m_pUnk->vtbl[435] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[435]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[435].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[435].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f435@_QIThunk@ATL@@UEAAJXZ


	.global ?f436@_QIThunk@ATL@@UEAAJXZ
	.proc	?f436@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f436@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=436*8,r14	// r14 = &m_pUnk->vtbl[436] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[436]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[436].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[436].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f436@_QIThunk@ATL@@UEAAJXZ


	.global ?f437@_QIThunk@ATL@@UEAAJXZ
	.proc	?f437@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f437@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=437*8,r14	// r14 = &m_pUnk->vtbl[437] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[437]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[437].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[437].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f437@_QIThunk@ATL@@UEAAJXZ


	.global ?f438@_QIThunk@ATL@@UEAAJXZ
	.proc	?f438@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f438@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=438*8,r14	// r14 = &m_pUnk->vtbl[438] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[438]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[438].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[438].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f438@_QIThunk@ATL@@UEAAJXZ


	.global ?f439@_QIThunk@ATL@@UEAAJXZ
	.proc	?f439@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f439@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=439*8,r14	// r14 = &m_pUnk->vtbl[439] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[439]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[439].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[439].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f439@_QIThunk@ATL@@UEAAJXZ


	.global ?f440@_QIThunk@ATL@@UEAAJXZ
	.proc	?f440@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f440@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=440*8,r14	// r14 = &m_pUnk->vtbl[440] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[440]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[440].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[440].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f440@_QIThunk@ATL@@UEAAJXZ


	.global ?f441@_QIThunk@ATL@@UEAAJXZ
	.proc	?f441@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f441@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=441*8,r14	// r14 = &m_pUnk->vtbl[441] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[441]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[441].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[441].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f441@_QIThunk@ATL@@UEAAJXZ


	.global ?f442@_QIThunk@ATL@@UEAAJXZ
	.proc	?f442@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f442@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=442*8,r14	// r14 = &m_pUnk->vtbl[442] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[442]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[442].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[442].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f442@_QIThunk@ATL@@UEAAJXZ


	.global ?f443@_QIThunk@ATL@@UEAAJXZ
	.proc	?f443@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f443@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=443*8,r14	// r14 = &m_pUnk->vtbl[443] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[443]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[443].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[443].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f443@_QIThunk@ATL@@UEAAJXZ


	.global ?f444@_QIThunk@ATL@@UEAAJXZ
	.proc	?f444@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f444@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=444*8,r14	// r14 = &m_pUnk->vtbl[444] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[444]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[444].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[444].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f444@_QIThunk@ATL@@UEAAJXZ


	.global ?f445@_QIThunk@ATL@@UEAAJXZ
	.proc	?f445@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f445@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=445*8,r14	// r14 = &m_pUnk->vtbl[445] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[445]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[445].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[445].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f445@_QIThunk@ATL@@UEAAJXZ


	.global ?f446@_QIThunk@ATL@@UEAAJXZ
	.proc	?f446@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f446@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=446*8,r14	// r14 = &m_pUnk->vtbl[446] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[446]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[446].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[446].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f446@_QIThunk@ATL@@UEAAJXZ


	.global ?f447@_QIThunk@ATL@@UEAAJXZ
	.proc	?f447@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f447@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=447*8,r14	// r14 = &m_pUnk->vtbl[447] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[447]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[447].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[447].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f447@_QIThunk@ATL@@UEAAJXZ


	.global ?f448@_QIThunk@ATL@@UEAAJXZ
	.proc	?f448@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f448@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=448*8,r14	// r14 = &m_pUnk->vtbl[448] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[448]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[448].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[448].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f448@_QIThunk@ATL@@UEAAJXZ


	.global ?f449@_QIThunk@ATL@@UEAAJXZ
	.proc	?f449@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f449@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=449*8,r14	// r14 = &m_pUnk->vtbl[449] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[449]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[449].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[449].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f449@_QIThunk@ATL@@UEAAJXZ


	.global ?f450@_QIThunk@ATL@@UEAAJXZ
	.proc	?f450@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f450@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=450*8,r14	// r14 = &m_pUnk->vtbl[450] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[450]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[450].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[450].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f450@_QIThunk@ATL@@UEAAJXZ


	.global ?f451@_QIThunk@ATL@@UEAAJXZ
	.proc	?f451@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f451@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=451*8,r14	// r14 = &m_pUnk->vtbl[451] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[451]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[451].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[451].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f451@_QIThunk@ATL@@UEAAJXZ


	.global ?f452@_QIThunk@ATL@@UEAAJXZ
	.proc	?f452@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f452@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=452*8,r14	// r14 = &m_pUnk->vtbl[452] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[452]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[452].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[452].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f452@_QIThunk@ATL@@UEAAJXZ


	.global ?f453@_QIThunk@ATL@@UEAAJXZ
	.proc	?f453@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f453@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=453*8,r14	// r14 = &m_pUnk->vtbl[453] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[453]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[453].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[453].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f453@_QIThunk@ATL@@UEAAJXZ


	.global ?f454@_QIThunk@ATL@@UEAAJXZ
	.proc	?f454@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f454@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=454*8,r14	// r14 = &m_pUnk->vtbl[454] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[454]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[454].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[454].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f454@_QIThunk@ATL@@UEAAJXZ


	.global ?f455@_QIThunk@ATL@@UEAAJXZ
	.proc	?f455@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f455@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=455*8,r14	// r14 = &m_pUnk->vtbl[455] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[455]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[455].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[455].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f455@_QIThunk@ATL@@UEAAJXZ


	.global ?f456@_QIThunk@ATL@@UEAAJXZ
	.proc	?f456@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f456@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=456*8,r14	// r14 = &m_pUnk->vtbl[456] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[456]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[456].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[456].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f456@_QIThunk@ATL@@UEAAJXZ


	.global ?f457@_QIThunk@ATL@@UEAAJXZ
	.proc	?f457@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f457@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=457*8,r14	// r14 = &m_pUnk->vtbl[457] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[457]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[457].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[457].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f457@_QIThunk@ATL@@UEAAJXZ


	.global ?f458@_QIThunk@ATL@@UEAAJXZ
	.proc	?f458@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f458@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=458*8,r14	// r14 = &m_pUnk->vtbl[458] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[458]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[458].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[458].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f458@_QIThunk@ATL@@UEAAJXZ


	.global ?f459@_QIThunk@ATL@@UEAAJXZ
	.proc	?f459@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f459@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=459*8,r14	// r14 = &m_pUnk->vtbl[459] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[459]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[459].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[459].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f459@_QIThunk@ATL@@UEAAJXZ


	.global ?f460@_QIThunk@ATL@@UEAAJXZ
	.proc	?f460@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f460@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=460*8,r14	// r14 = &m_pUnk->vtbl[460] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[460]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[460].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[460].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f460@_QIThunk@ATL@@UEAAJXZ


	.global ?f461@_QIThunk@ATL@@UEAAJXZ
	.proc	?f461@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f461@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=461*8,r14	// r14 = &m_pUnk->vtbl[461] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[461]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[461].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[461].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f461@_QIThunk@ATL@@UEAAJXZ


	.global ?f462@_QIThunk@ATL@@UEAAJXZ
	.proc	?f462@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f462@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=462*8,r14	// r14 = &m_pUnk->vtbl[462] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[462]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[462].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[462].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f462@_QIThunk@ATL@@UEAAJXZ


	.global ?f463@_QIThunk@ATL@@UEAAJXZ
	.proc	?f463@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f463@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=463*8,r14	// r14 = &m_pUnk->vtbl[463] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[463]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[463].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[463].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f463@_QIThunk@ATL@@UEAAJXZ


	.global ?f464@_QIThunk@ATL@@UEAAJXZ
	.proc	?f464@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f464@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=464*8,r14	// r14 = &m_pUnk->vtbl[464] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[464]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[464].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[464].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f464@_QIThunk@ATL@@UEAAJXZ


	.global ?f465@_QIThunk@ATL@@UEAAJXZ
	.proc	?f465@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f465@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=465*8,r14	// r14 = &m_pUnk->vtbl[465] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[465]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[465].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[465].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f465@_QIThunk@ATL@@UEAAJXZ


	.global ?f466@_QIThunk@ATL@@UEAAJXZ
	.proc	?f466@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f466@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=466*8,r14	// r14 = &m_pUnk->vtbl[466] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[466]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[466].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[466].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f466@_QIThunk@ATL@@UEAAJXZ


	.global ?f467@_QIThunk@ATL@@UEAAJXZ
	.proc	?f467@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f467@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=467*8,r14	// r14 = &m_pUnk->vtbl[467] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[467]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[467].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[467].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f467@_QIThunk@ATL@@UEAAJXZ


	.global ?f468@_QIThunk@ATL@@UEAAJXZ
	.proc	?f468@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f468@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=468*8,r14	// r14 = &m_pUnk->vtbl[468] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[468]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[468].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[468].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f468@_QIThunk@ATL@@UEAAJXZ


	.global ?f469@_QIThunk@ATL@@UEAAJXZ
	.proc	?f469@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f469@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=469*8,r14	// r14 = &m_pUnk->vtbl[469] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[469]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[469].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[469].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f469@_QIThunk@ATL@@UEAAJXZ


	.global ?f470@_QIThunk@ATL@@UEAAJXZ
	.proc	?f470@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f470@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=470*8,r14	// r14 = &m_pUnk->vtbl[470] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[470]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[470].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[470].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f470@_QIThunk@ATL@@UEAAJXZ


	.global ?f471@_QIThunk@ATL@@UEAAJXZ
	.proc	?f471@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f471@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=471*8,r14	// r14 = &m_pUnk->vtbl[471] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[471]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[471].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[471].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f471@_QIThunk@ATL@@UEAAJXZ


	.global ?f472@_QIThunk@ATL@@UEAAJXZ
	.proc	?f472@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f472@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=472*8,r14	// r14 = &m_pUnk->vtbl[472] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[472]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[472].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[472].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f472@_QIThunk@ATL@@UEAAJXZ


	.global ?f473@_QIThunk@ATL@@UEAAJXZ
	.proc	?f473@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f473@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=473*8,r14	// r14 = &m_pUnk->vtbl[473] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[473]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[473].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[473].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f473@_QIThunk@ATL@@UEAAJXZ


	.global ?f474@_QIThunk@ATL@@UEAAJXZ
	.proc	?f474@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f474@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=474*8,r14	// r14 = &m_pUnk->vtbl[474] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[474]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[474].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[474].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f474@_QIThunk@ATL@@UEAAJXZ


	.global ?f475@_QIThunk@ATL@@UEAAJXZ
	.proc	?f475@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f475@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=475*8,r14	// r14 = &m_pUnk->vtbl[475] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[475]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[475].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[475].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f475@_QIThunk@ATL@@UEAAJXZ


	.global ?f476@_QIThunk@ATL@@UEAAJXZ
	.proc	?f476@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f476@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=476*8,r14	// r14 = &m_pUnk->vtbl[476] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[476]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[476].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[476].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f476@_QIThunk@ATL@@UEAAJXZ


	.global ?f477@_QIThunk@ATL@@UEAAJXZ
	.proc	?f477@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f477@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=477*8,r14	// r14 = &m_pUnk->vtbl[477] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[477]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[477].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[477].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f477@_QIThunk@ATL@@UEAAJXZ


	.global ?f478@_QIThunk@ATL@@UEAAJXZ
	.proc	?f478@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f478@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=478*8,r14	// r14 = &m_pUnk->vtbl[478] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[478]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[478].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[478].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f478@_QIThunk@ATL@@UEAAJXZ


	.global ?f479@_QIThunk@ATL@@UEAAJXZ
	.proc	?f479@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f479@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=479*8,r14	// r14 = &m_pUnk->vtbl[479] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[479]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[479].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[479].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f479@_QIThunk@ATL@@UEAAJXZ


	.global ?f480@_QIThunk@ATL@@UEAAJXZ
	.proc	?f480@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f480@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=480*8,r14	// r14 = &m_pUnk->vtbl[480] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[480]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[480].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[480].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f480@_QIThunk@ATL@@UEAAJXZ


	.global ?f481@_QIThunk@ATL@@UEAAJXZ
	.proc	?f481@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f481@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=481*8,r14	// r14 = &m_pUnk->vtbl[481] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[481]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[481].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[481].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f481@_QIThunk@ATL@@UEAAJXZ


	.global ?f482@_QIThunk@ATL@@UEAAJXZ
	.proc	?f482@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f482@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=482*8,r14	// r14 = &m_pUnk->vtbl[482] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[482]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[482].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[482].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f482@_QIThunk@ATL@@UEAAJXZ


	.global ?f483@_QIThunk@ATL@@UEAAJXZ
	.proc	?f483@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f483@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=483*8,r14	// r14 = &m_pUnk->vtbl[483] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[483]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[483].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[483].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f483@_QIThunk@ATL@@UEAAJXZ


	.global ?f484@_QIThunk@ATL@@UEAAJXZ
	.proc	?f484@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f484@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=484*8,r14	// r14 = &m_pUnk->vtbl[484] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[484]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[484].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[484].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f484@_QIThunk@ATL@@UEAAJXZ


	.global ?f485@_QIThunk@ATL@@UEAAJXZ
	.proc	?f485@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f485@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=485*8,r14	// r14 = &m_pUnk->vtbl[485] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[485]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[485].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[485].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f485@_QIThunk@ATL@@UEAAJXZ


	.global ?f486@_QIThunk@ATL@@UEAAJXZ
	.proc	?f486@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f486@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=486*8,r14	// r14 = &m_pUnk->vtbl[486] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[486]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[486].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[486].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f486@_QIThunk@ATL@@UEAAJXZ


	.global ?f487@_QIThunk@ATL@@UEAAJXZ
	.proc	?f487@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f487@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=487*8,r14	// r14 = &m_pUnk->vtbl[487] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[487]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[487].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[487].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f487@_QIThunk@ATL@@UEAAJXZ


	.global ?f488@_QIThunk@ATL@@UEAAJXZ
	.proc	?f488@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f488@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=488*8,r14	// r14 = &m_pUnk->vtbl[488] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[488]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[488].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[488].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f488@_QIThunk@ATL@@UEAAJXZ


	.global ?f489@_QIThunk@ATL@@UEAAJXZ
	.proc	?f489@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f489@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=489*8,r14	// r14 = &m_pUnk->vtbl[489] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[489]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[489].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[489].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f489@_QIThunk@ATL@@UEAAJXZ


	.global ?f490@_QIThunk@ATL@@UEAAJXZ
	.proc	?f490@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f490@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=490*8,r14	// r14 = &m_pUnk->vtbl[490] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[490]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[490].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[490].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f490@_QIThunk@ATL@@UEAAJXZ


	.global ?f491@_QIThunk@ATL@@UEAAJXZ
	.proc	?f491@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f491@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=491*8,r14	// r14 = &m_pUnk->vtbl[491] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[491]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[491].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[491].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f491@_QIThunk@ATL@@UEAAJXZ


	.global ?f492@_QIThunk@ATL@@UEAAJXZ
	.proc	?f492@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f492@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=492*8,r14	// r14 = &m_pUnk->vtbl[492] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[492]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[492].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[492].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f492@_QIThunk@ATL@@UEAAJXZ


	.global ?f493@_QIThunk@ATL@@UEAAJXZ
	.proc	?f493@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f493@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=493*8,r14	// r14 = &m_pUnk->vtbl[493] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[493]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[493].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[493].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f493@_QIThunk@ATL@@UEAAJXZ


	.global ?f494@_QIThunk@ATL@@UEAAJXZ
	.proc	?f494@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f494@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=494*8,r14	// r14 = &m_pUnk->vtbl[494] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[494]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[494].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[494].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f494@_QIThunk@ATL@@UEAAJXZ


	.global ?f495@_QIThunk@ATL@@UEAAJXZ
	.proc	?f495@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f495@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=495*8,r14	// r14 = &m_pUnk->vtbl[495] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[495]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[495].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[495].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f495@_QIThunk@ATL@@UEAAJXZ


	.global ?f496@_QIThunk@ATL@@UEAAJXZ
	.proc	?f496@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f496@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=496*8,r14	// r14 = &m_pUnk->vtbl[496] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[496]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[496].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[496].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f496@_QIThunk@ATL@@UEAAJXZ


	.global ?f497@_QIThunk@ATL@@UEAAJXZ
	.proc	?f497@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f497@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=497*8,r14	// r14 = &m_pUnk->vtbl[497] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[497]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[497].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[497].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f497@_QIThunk@ATL@@UEAAJXZ


	.global ?f498@_QIThunk@ATL@@UEAAJXZ
	.proc	?f498@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f498@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=498*8,r14	// r14 = &m_pUnk->vtbl[498] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[498]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[498].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[498].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f498@_QIThunk@ATL@@UEAAJXZ


	.global ?f499@_QIThunk@ATL@@UEAAJXZ
	.proc	?f499@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f499@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=499*8,r14	// r14 = &m_pUnk->vtbl[499] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[499]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[499].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[499].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f499@_QIThunk@ATL@@UEAAJXZ


	.global ?f500@_QIThunk@ATL@@UEAAJXZ
	.proc	?f500@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f500@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=500*8,r14	// r14 = &m_pUnk->vtbl[500] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[500]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[500].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[500].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f500@_QIThunk@ATL@@UEAAJXZ


	.global ?f501@_QIThunk@ATL@@UEAAJXZ
	.proc	?f501@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f501@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=501*8,r14	// r14 = &m_pUnk->vtbl[501] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[501]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[501].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[501].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f501@_QIThunk@ATL@@UEAAJXZ


	.global ?f502@_QIThunk@ATL@@UEAAJXZ
	.proc	?f502@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f502@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=502*8,r14	// r14 = &m_pUnk->vtbl[502] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[502]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[502].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[502].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f502@_QIThunk@ATL@@UEAAJXZ


	.global ?f503@_QIThunk@ATL@@UEAAJXZ
	.proc	?f503@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f503@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=503*8,r14	// r14 = &m_pUnk->vtbl[503] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[503]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[503].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[503].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f503@_QIThunk@ATL@@UEAAJXZ


	.global ?f504@_QIThunk@ATL@@UEAAJXZ
	.proc	?f504@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f504@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=504*8,r14	// r14 = &m_pUnk->vtbl[504] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[504]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[504].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[504].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f504@_QIThunk@ATL@@UEAAJXZ


	.global ?f505@_QIThunk@ATL@@UEAAJXZ
	.proc	?f505@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f505@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=505*8,r14	// r14 = &m_pUnk->vtbl[505] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[505]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[505].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[505].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f505@_QIThunk@ATL@@UEAAJXZ


	.global ?f506@_QIThunk@ATL@@UEAAJXZ
	.proc	?f506@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f506@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=506*8,r14	// r14 = &m_pUnk->vtbl[506] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[506]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[506].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[506].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f506@_QIThunk@ATL@@UEAAJXZ


	.global ?f507@_QIThunk@ATL@@UEAAJXZ
	.proc	?f507@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f507@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=507*8,r14	// r14 = &m_pUnk->vtbl[507] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[507]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[507].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[507].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f507@_QIThunk@ATL@@UEAAJXZ


	.global ?f508@_QIThunk@ATL@@UEAAJXZ
	.proc	?f508@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f508@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=508*8,r14	// r14 = &m_pUnk->vtbl[508] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[508]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[508].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[508].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f508@_QIThunk@ATL@@UEAAJXZ


	.global ?f509@_QIThunk@ATL@@UEAAJXZ
	.proc	?f509@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f509@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=509*8,r14	// r14 = &m_pUnk->vtbl[509] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[509]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[509].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[509].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f509@_QIThunk@ATL@@UEAAJXZ


	.global ?f510@_QIThunk@ATL@@UEAAJXZ
	.proc	?f510@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f510@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=510*8,r14	// r14 = &m_pUnk->vtbl[510] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[510]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[510].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[510].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f510@_QIThunk@ATL@@UEAAJXZ


	.global ?f511@_QIThunk@ATL@@UEAAJXZ
	.proc	?f511@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f511@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=511*8,r14	// r14 = &m_pUnk->vtbl[511] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[511]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[511].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[511].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f511@_QIThunk@ATL@@UEAAJXZ


	.global ?f512@_QIThunk@ATL@@UEAAJXZ
	.proc	?f512@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f512@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=512*8,r14	// r14 = &m_pUnk->vtbl[512] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[512]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[512].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[512].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f512@_QIThunk@ATL@@UEAAJXZ


	.global ?f513@_QIThunk@ATL@@UEAAJXZ
	.proc	?f513@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f513@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=513*8,r14	// r14 = &m_pUnk->vtbl[513] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[513]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[513].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[513].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f513@_QIThunk@ATL@@UEAAJXZ


	.global ?f514@_QIThunk@ATL@@UEAAJXZ
	.proc	?f514@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f514@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=514*8,r14	// r14 = &m_pUnk->vtbl[514] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[514]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[514].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[514].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f514@_QIThunk@ATL@@UEAAJXZ


	.global ?f515@_QIThunk@ATL@@UEAAJXZ
	.proc	?f515@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f515@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=515*8,r14	// r14 = &m_pUnk->vtbl[515] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[515]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[515].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[515].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f515@_QIThunk@ATL@@UEAAJXZ


	.global ?f516@_QIThunk@ATL@@UEAAJXZ
	.proc	?f516@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f516@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=516*8,r14	// r14 = &m_pUnk->vtbl[516] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[516]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[516].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[516].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f516@_QIThunk@ATL@@UEAAJXZ


	.global ?f517@_QIThunk@ATL@@UEAAJXZ
	.proc	?f517@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f517@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=517*8,r14	// r14 = &m_pUnk->vtbl[517] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[517]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[517].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[517].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f517@_QIThunk@ATL@@UEAAJXZ


	.global ?f518@_QIThunk@ATL@@UEAAJXZ
	.proc	?f518@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f518@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=518*8,r14	// r14 = &m_pUnk->vtbl[518] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[518]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[518].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[518].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f518@_QIThunk@ATL@@UEAAJXZ


	.global ?f519@_QIThunk@ATL@@UEAAJXZ
	.proc	?f519@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f519@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=519*8,r14	// r14 = &m_pUnk->vtbl[519] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[519]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[519].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[519].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f519@_QIThunk@ATL@@UEAAJXZ


	.global ?f520@_QIThunk@ATL@@UEAAJXZ
	.proc	?f520@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f520@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=520*8,r14	// r14 = &m_pUnk->vtbl[520] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[520]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[520].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[520].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f520@_QIThunk@ATL@@UEAAJXZ


	.global ?f521@_QIThunk@ATL@@UEAAJXZ
	.proc	?f521@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f521@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=521*8,r14	// r14 = &m_pUnk->vtbl[521] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[521]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[521].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[521].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f521@_QIThunk@ATL@@UEAAJXZ


	.global ?f522@_QIThunk@ATL@@UEAAJXZ
	.proc	?f522@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f522@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=522*8,r14	// r14 = &m_pUnk->vtbl[522] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[522]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[522].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[522].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f522@_QIThunk@ATL@@UEAAJXZ


	.global ?f523@_QIThunk@ATL@@UEAAJXZ
	.proc	?f523@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f523@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=523*8,r14	// r14 = &m_pUnk->vtbl[523] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[523]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[523].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[523].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f523@_QIThunk@ATL@@UEAAJXZ


	.global ?f524@_QIThunk@ATL@@UEAAJXZ
	.proc	?f524@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f524@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=524*8,r14	// r14 = &m_pUnk->vtbl[524] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[524]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[524].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[524].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f524@_QIThunk@ATL@@UEAAJXZ


	.global ?f525@_QIThunk@ATL@@UEAAJXZ
	.proc	?f525@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f525@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=525*8,r14	// r14 = &m_pUnk->vtbl[525] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[525]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[525].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[525].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f525@_QIThunk@ATL@@UEAAJXZ


	.global ?f526@_QIThunk@ATL@@UEAAJXZ
	.proc	?f526@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f526@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=526*8,r14	// r14 = &m_pUnk->vtbl[526] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[526]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[526].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[526].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f526@_QIThunk@ATL@@UEAAJXZ


	.global ?f527@_QIThunk@ATL@@UEAAJXZ
	.proc	?f527@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f527@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=527*8,r14	// r14 = &m_pUnk->vtbl[527] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[527]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[527].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[527].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f527@_QIThunk@ATL@@UEAAJXZ


	.global ?f528@_QIThunk@ATL@@UEAAJXZ
	.proc	?f528@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f528@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=528*8,r14	// r14 = &m_pUnk->vtbl[528] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[528]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[528].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[528].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f528@_QIThunk@ATL@@UEAAJXZ


	.global ?f529@_QIThunk@ATL@@UEAAJXZ
	.proc	?f529@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f529@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=529*8,r14	// r14 = &m_pUnk->vtbl[529] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[529]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[529].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[529].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f529@_QIThunk@ATL@@UEAAJXZ


	.global ?f530@_QIThunk@ATL@@UEAAJXZ
	.proc	?f530@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f530@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=530*8,r14	// r14 = &m_pUnk->vtbl[530] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[530]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[530].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[530].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f530@_QIThunk@ATL@@UEAAJXZ


	.global ?f531@_QIThunk@ATL@@UEAAJXZ
	.proc	?f531@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f531@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=531*8,r14	// r14 = &m_pUnk->vtbl[531] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[531]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[531].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[531].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f531@_QIThunk@ATL@@UEAAJXZ


	.global ?f532@_QIThunk@ATL@@UEAAJXZ
	.proc	?f532@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f532@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=532*8,r14	// r14 = &m_pUnk->vtbl[532] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[532]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[532].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[532].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f532@_QIThunk@ATL@@UEAAJXZ


	.global ?f533@_QIThunk@ATL@@UEAAJXZ
	.proc	?f533@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f533@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=533*8,r14	// r14 = &m_pUnk->vtbl[533] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[533]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[533].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[533].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f533@_QIThunk@ATL@@UEAAJXZ


	.global ?f534@_QIThunk@ATL@@UEAAJXZ
	.proc	?f534@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f534@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=534*8,r14	// r14 = &m_pUnk->vtbl[534] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[534]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[534].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[534].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f534@_QIThunk@ATL@@UEAAJXZ


	.global ?f535@_QIThunk@ATL@@UEAAJXZ
	.proc	?f535@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f535@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=535*8,r14	// r14 = &m_pUnk->vtbl[535] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[535]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[535].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[535].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f535@_QIThunk@ATL@@UEAAJXZ


	.global ?f536@_QIThunk@ATL@@UEAAJXZ
	.proc	?f536@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f536@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=536*8,r14	// r14 = &m_pUnk->vtbl[536] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[536]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[536].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[536].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f536@_QIThunk@ATL@@UEAAJXZ


	.global ?f537@_QIThunk@ATL@@UEAAJXZ
	.proc	?f537@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f537@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=537*8,r14	// r14 = &m_pUnk->vtbl[537] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[537]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[537].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[537].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f537@_QIThunk@ATL@@UEAAJXZ


	.global ?f538@_QIThunk@ATL@@UEAAJXZ
	.proc	?f538@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f538@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=538*8,r14	// r14 = &m_pUnk->vtbl[538] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[538]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[538].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[538].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f538@_QIThunk@ATL@@UEAAJXZ


	.global ?f539@_QIThunk@ATL@@UEAAJXZ
	.proc	?f539@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f539@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=539*8,r14	// r14 = &m_pUnk->vtbl[539] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[539]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[539].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[539].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f539@_QIThunk@ATL@@UEAAJXZ


	.global ?f540@_QIThunk@ATL@@UEAAJXZ
	.proc	?f540@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f540@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=540*8,r14	// r14 = &m_pUnk->vtbl[540] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[540]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[540].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[540].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f540@_QIThunk@ATL@@UEAAJXZ


	.global ?f541@_QIThunk@ATL@@UEAAJXZ
	.proc	?f541@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f541@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=541*8,r14	// r14 = &m_pUnk->vtbl[541] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[541]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[541].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[541].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f541@_QIThunk@ATL@@UEAAJXZ


	.global ?f542@_QIThunk@ATL@@UEAAJXZ
	.proc	?f542@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f542@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=542*8,r14	// r14 = &m_pUnk->vtbl[542] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[542]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[542].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[542].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f542@_QIThunk@ATL@@UEAAJXZ


	.global ?f543@_QIThunk@ATL@@UEAAJXZ
	.proc	?f543@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f543@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=543*8,r14	// r14 = &m_pUnk->vtbl[543] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[543]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[543].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[543].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f543@_QIThunk@ATL@@UEAAJXZ


	.global ?f544@_QIThunk@ATL@@UEAAJXZ
	.proc	?f544@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f544@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=544*8,r14	// r14 = &m_pUnk->vtbl[544] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[544]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[544].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[544].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f544@_QIThunk@ATL@@UEAAJXZ


	.global ?f545@_QIThunk@ATL@@UEAAJXZ
	.proc	?f545@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f545@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=545*8,r14	// r14 = &m_pUnk->vtbl[545] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[545]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[545].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[545].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f545@_QIThunk@ATL@@UEAAJXZ


	.global ?f546@_QIThunk@ATL@@UEAAJXZ
	.proc	?f546@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f546@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=546*8,r14	// r14 = &m_pUnk->vtbl[546] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[546]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[546].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[546].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f546@_QIThunk@ATL@@UEAAJXZ


	.global ?f547@_QIThunk@ATL@@UEAAJXZ
	.proc	?f547@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f547@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=547*8,r14	// r14 = &m_pUnk->vtbl[547] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[547]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[547].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[547].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f547@_QIThunk@ATL@@UEAAJXZ


	.global ?f548@_QIThunk@ATL@@UEAAJXZ
	.proc	?f548@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f548@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=548*8,r14	// r14 = &m_pUnk->vtbl[548] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[548]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[548].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[548].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f548@_QIThunk@ATL@@UEAAJXZ


	.global ?f549@_QIThunk@ATL@@UEAAJXZ
	.proc	?f549@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f549@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=549*8,r14	// r14 = &m_pUnk->vtbl[549] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[549]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[549].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[549].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f549@_QIThunk@ATL@@UEAAJXZ


	.global ?f550@_QIThunk@ATL@@UEAAJXZ
	.proc	?f550@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f550@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=550*8,r14	// r14 = &m_pUnk->vtbl[550] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[550]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[550].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[550].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f550@_QIThunk@ATL@@UEAAJXZ


	.global ?f551@_QIThunk@ATL@@UEAAJXZ
	.proc	?f551@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f551@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=551*8,r14	// r14 = &m_pUnk->vtbl[551] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[551]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[551].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[551].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f551@_QIThunk@ATL@@UEAAJXZ


	.global ?f552@_QIThunk@ATL@@UEAAJXZ
	.proc	?f552@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f552@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=552*8,r14	// r14 = &m_pUnk->vtbl[552] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[552]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[552].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[552].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f552@_QIThunk@ATL@@UEAAJXZ


	.global ?f553@_QIThunk@ATL@@UEAAJXZ
	.proc	?f553@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f553@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=553*8,r14	// r14 = &m_pUnk->vtbl[553] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[553]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[553].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[553].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f553@_QIThunk@ATL@@UEAAJXZ


	.global ?f554@_QIThunk@ATL@@UEAAJXZ
	.proc	?f554@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f554@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=554*8,r14	// r14 = &m_pUnk->vtbl[554] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[554]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[554].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[554].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f554@_QIThunk@ATL@@UEAAJXZ


	.global ?f555@_QIThunk@ATL@@UEAAJXZ
	.proc	?f555@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f555@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=555*8,r14	// r14 = &m_pUnk->vtbl[555] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[555]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[555].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[555].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f555@_QIThunk@ATL@@UEAAJXZ


	.global ?f556@_QIThunk@ATL@@UEAAJXZ
	.proc	?f556@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f556@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=556*8,r14	// r14 = &m_pUnk->vtbl[556] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[556]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[556].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[556].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f556@_QIThunk@ATL@@UEAAJXZ


	.global ?f557@_QIThunk@ATL@@UEAAJXZ
	.proc	?f557@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f557@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=557*8,r14	// r14 = &m_pUnk->vtbl[557] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[557]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[557].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[557].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f557@_QIThunk@ATL@@UEAAJXZ


	.global ?f558@_QIThunk@ATL@@UEAAJXZ
	.proc	?f558@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f558@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=558*8,r14	// r14 = &m_pUnk->vtbl[558] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[558]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[558].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[558].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f558@_QIThunk@ATL@@UEAAJXZ


	.global ?f559@_QIThunk@ATL@@UEAAJXZ
	.proc	?f559@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f559@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=559*8,r14	// r14 = &m_pUnk->vtbl[559] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[559]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[559].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[559].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f559@_QIThunk@ATL@@UEAAJXZ


	.global ?f560@_QIThunk@ATL@@UEAAJXZ
	.proc	?f560@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f560@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=560*8,r14	// r14 = &m_pUnk->vtbl[560] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[560]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[560].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[560].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f560@_QIThunk@ATL@@UEAAJXZ


	.global ?f561@_QIThunk@ATL@@UEAAJXZ
	.proc	?f561@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f561@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=561*8,r14	// r14 = &m_pUnk->vtbl[561] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[561]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[561].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[561].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f561@_QIThunk@ATL@@UEAAJXZ


	.global ?f562@_QIThunk@ATL@@UEAAJXZ
	.proc	?f562@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f562@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=562*8,r14	// r14 = &m_pUnk->vtbl[562] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[562]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[562].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[562].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f562@_QIThunk@ATL@@UEAAJXZ


	.global ?f563@_QIThunk@ATL@@UEAAJXZ
	.proc	?f563@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f563@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=563*8,r14	// r14 = &m_pUnk->vtbl[563] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[563]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[563].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[563].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f563@_QIThunk@ATL@@UEAAJXZ


	.global ?f564@_QIThunk@ATL@@UEAAJXZ
	.proc	?f564@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f564@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=564*8,r14	// r14 = &m_pUnk->vtbl[564] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[564]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[564].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[564].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f564@_QIThunk@ATL@@UEAAJXZ


	.global ?f565@_QIThunk@ATL@@UEAAJXZ
	.proc	?f565@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f565@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=565*8,r14	// r14 = &m_pUnk->vtbl[565] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[565]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[565].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[565].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f565@_QIThunk@ATL@@UEAAJXZ


	.global ?f566@_QIThunk@ATL@@UEAAJXZ
	.proc	?f566@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f566@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=566*8,r14	// r14 = &m_pUnk->vtbl[566] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[566]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[566].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[566].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f566@_QIThunk@ATL@@UEAAJXZ


	.global ?f567@_QIThunk@ATL@@UEAAJXZ
	.proc	?f567@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f567@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=567*8,r14	// r14 = &m_pUnk->vtbl[567] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[567]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[567].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[567].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f567@_QIThunk@ATL@@UEAAJXZ


	.global ?f568@_QIThunk@ATL@@UEAAJXZ
	.proc	?f568@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f568@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=568*8,r14	// r14 = &m_pUnk->vtbl[568] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[568]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[568].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[568].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f568@_QIThunk@ATL@@UEAAJXZ


	.global ?f569@_QIThunk@ATL@@UEAAJXZ
	.proc	?f569@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f569@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=569*8,r14	// r14 = &m_pUnk->vtbl[569] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[569]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[569].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[569].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f569@_QIThunk@ATL@@UEAAJXZ


	.global ?f570@_QIThunk@ATL@@UEAAJXZ
	.proc	?f570@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f570@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=570*8,r14	// r14 = &m_pUnk->vtbl[570] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[570]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[570].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[570].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f570@_QIThunk@ATL@@UEAAJXZ


	.global ?f571@_QIThunk@ATL@@UEAAJXZ
	.proc	?f571@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f571@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=571*8,r14	// r14 = &m_pUnk->vtbl[571] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[571]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[571].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[571].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f571@_QIThunk@ATL@@UEAAJXZ


	.global ?f572@_QIThunk@ATL@@UEAAJXZ
	.proc	?f572@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f572@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=572*8,r14	// r14 = &m_pUnk->vtbl[572] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[572]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[572].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[572].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f572@_QIThunk@ATL@@UEAAJXZ


	.global ?f573@_QIThunk@ATL@@UEAAJXZ
	.proc	?f573@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f573@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=573*8,r14	// r14 = &m_pUnk->vtbl[573] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[573]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[573].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[573].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f573@_QIThunk@ATL@@UEAAJXZ


	.global ?f574@_QIThunk@ATL@@UEAAJXZ
	.proc	?f574@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f574@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=574*8,r14	// r14 = &m_pUnk->vtbl[574] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[574]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[574].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[574].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f574@_QIThunk@ATL@@UEAAJXZ


	.global ?f575@_QIThunk@ATL@@UEAAJXZ
	.proc	?f575@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f575@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=575*8,r14	// r14 = &m_pUnk->vtbl[575] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[575]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[575].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[575].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f575@_QIThunk@ATL@@UEAAJXZ


	.global ?f576@_QIThunk@ATL@@UEAAJXZ
	.proc	?f576@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f576@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=576*8,r14	// r14 = &m_pUnk->vtbl[576] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[576]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[576].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[576].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f576@_QIThunk@ATL@@UEAAJXZ


	.global ?f577@_QIThunk@ATL@@UEAAJXZ
	.proc	?f577@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f577@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=577*8,r14	// r14 = &m_pUnk->vtbl[577] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[577]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[577].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[577].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f577@_QIThunk@ATL@@UEAAJXZ


	.global ?f578@_QIThunk@ATL@@UEAAJXZ
	.proc	?f578@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f578@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=578*8,r14	// r14 = &m_pUnk->vtbl[578] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[578]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[578].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[578].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f578@_QIThunk@ATL@@UEAAJXZ


	.global ?f579@_QIThunk@ATL@@UEAAJXZ
	.proc	?f579@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f579@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=579*8,r14	// r14 = &m_pUnk->vtbl[579] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[579]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[579].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[579].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f579@_QIThunk@ATL@@UEAAJXZ


	.global ?f580@_QIThunk@ATL@@UEAAJXZ
	.proc	?f580@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f580@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=580*8,r14	// r14 = &m_pUnk->vtbl[580] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[580]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[580].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[580].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f580@_QIThunk@ATL@@UEAAJXZ


	.global ?f581@_QIThunk@ATL@@UEAAJXZ
	.proc	?f581@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f581@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=581*8,r14	// r14 = &m_pUnk->vtbl[581] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[581]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[581].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[581].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f581@_QIThunk@ATL@@UEAAJXZ


	.global ?f582@_QIThunk@ATL@@UEAAJXZ
	.proc	?f582@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f582@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=582*8,r14	// r14 = &m_pUnk->vtbl[582] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[582]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[582].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[582].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f582@_QIThunk@ATL@@UEAAJXZ


	.global ?f583@_QIThunk@ATL@@UEAAJXZ
	.proc	?f583@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f583@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=583*8,r14	// r14 = &m_pUnk->vtbl[583] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[583]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[583].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[583].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f583@_QIThunk@ATL@@UEAAJXZ


	.global ?f584@_QIThunk@ATL@@UEAAJXZ
	.proc	?f584@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f584@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=584*8,r14	// r14 = &m_pUnk->vtbl[584] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[584]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[584].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[584].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f584@_QIThunk@ATL@@UEAAJXZ


	.global ?f585@_QIThunk@ATL@@UEAAJXZ
	.proc	?f585@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f585@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=585*8,r14	// r14 = &m_pUnk->vtbl[585] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[585]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[585].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[585].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f585@_QIThunk@ATL@@UEAAJXZ


	.global ?f586@_QIThunk@ATL@@UEAAJXZ
	.proc	?f586@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f586@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=586*8,r14	// r14 = &m_pUnk->vtbl[586] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[586]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[586].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[586].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f586@_QIThunk@ATL@@UEAAJXZ


	.global ?f587@_QIThunk@ATL@@UEAAJXZ
	.proc	?f587@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f587@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=587*8,r14	// r14 = &m_pUnk->vtbl[587] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[587]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[587].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[587].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f587@_QIThunk@ATL@@UEAAJXZ


	.global ?f588@_QIThunk@ATL@@UEAAJXZ
	.proc	?f588@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f588@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=588*8,r14	// r14 = &m_pUnk->vtbl[588] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[588]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[588].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[588].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f588@_QIThunk@ATL@@UEAAJXZ


	.global ?f589@_QIThunk@ATL@@UEAAJXZ
	.proc	?f589@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f589@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=589*8,r14	// r14 = &m_pUnk->vtbl[589] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[589]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[589].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[589].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f589@_QIThunk@ATL@@UEAAJXZ


	.global ?f590@_QIThunk@ATL@@UEAAJXZ
	.proc	?f590@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f590@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=590*8,r14	// r14 = &m_pUnk->vtbl[590] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[590]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[590].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[590].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f590@_QIThunk@ATL@@UEAAJXZ


	.global ?f591@_QIThunk@ATL@@UEAAJXZ
	.proc	?f591@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f591@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=591*8,r14	// r14 = &m_pUnk->vtbl[591] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[591]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[591].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[591].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f591@_QIThunk@ATL@@UEAAJXZ


	.global ?f592@_QIThunk@ATL@@UEAAJXZ
	.proc	?f592@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f592@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=592*8,r14	// r14 = &m_pUnk->vtbl[592] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[592]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[592].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[592].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f592@_QIThunk@ATL@@UEAAJXZ


	.global ?f593@_QIThunk@ATL@@UEAAJXZ
	.proc	?f593@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f593@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=593*8,r14	// r14 = &m_pUnk->vtbl[593] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[593]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[593].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[593].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f593@_QIThunk@ATL@@UEAAJXZ


	.global ?f594@_QIThunk@ATL@@UEAAJXZ
	.proc	?f594@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f594@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=594*8,r14	// r14 = &m_pUnk->vtbl[594] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[594]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[594].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[594].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f594@_QIThunk@ATL@@UEAAJXZ


	.global ?f595@_QIThunk@ATL@@UEAAJXZ
	.proc	?f595@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f595@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=595*8,r14	// r14 = &m_pUnk->vtbl[595] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[595]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[595].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[595].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f595@_QIThunk@ATL@@UEAAJXZ


	.global ?f596@_QIThunk@ATL@@UEAAJXZ
	.proc	?f596@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f596@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=596*8,r14	// r14 = &m_pUnk->vtbl[596] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[596]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[596].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[596].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f596@_QIThunk@ATL@@UEAAJXZ


	.global ?f597@_QIThunk@ATL@@UEAAJXZ
	.proc	?f597@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f597@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=597*8,r14	// r14 = &m_pUnk->vtbl[597] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[597]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[597].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[597].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f597@_QIThunk@ATL@@UEAAJXZ


	.global ?f598@_QIThunk@ATL@@UEAAJXZ
	.proc	?f598@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f598@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=598*8,r14	// r14 = &m_pUnk->vtbl[598] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[598]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[598].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[598].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f598@_QIThunk@ATL@@UEAAJXZ


	.global ?f599@_QIThunk@ATL@@UEAAJXZ
	.proc	?f599@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f599@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=599*8,r14	// r14 = &m_pUnk->vtbl[599] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[599]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[599].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[599].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f599@_QIThunk@ATL@@UEAAJXZ


	.global ?f600@_QIThunk@ATL@@UEAAJXZ
	.proc	?f600@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f600@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=600*8,r14	// r14 = &m_pUnk->vtbl[600] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[600]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[600].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[600].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f600@_QIThunk@ATL@@UEAAJXZ


	.global ?f601@_QIThunk@ATL@@UEAAJXZ
	.proc	?f601@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f601@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=601*8,r14	// r14 = &m_pUnk->vtbl[601] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[601]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[601].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[601].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f601@_QIThunk@ATL@@UEAAJXZ


	.global ?f602@_QIThunk@ATL@@UEAAJXZ
	.proc	?f602@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f602@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=602*8,r14	// r14 = &m_pUnk->vtbl[602] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[602]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[602].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[602].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f602@_QIThunk@ATL@@UEAAJXZ


	.global ?f603@_QIThunk@ATL@@UEAAJXZ
	.proc	?f603@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f603@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=603*8,r14	// r14 = &m_pUnk->vtbl[603] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[603]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[603].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[603].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f603@_QIThunk@ATL@@UEAAJXZ


	.global ?f604@_QIThunk@ATL@@UEAAJXZ
	.proc	?f604@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f604@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=604*8,r14	// r14 = &m_pUnk->vtbl[604] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[604]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[604].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[604].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f604@_QIThunk@ATL@@UEAAJXZ


	.global ?f605@_QIThunk@ATL@@UEAAJXZ
	.proc	?f605@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f605@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=605*8,r14	// r14 = &m_pUnk->vtbl[605] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[605]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[605].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[605].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f605@_QIThunk@ATL@@UEAAJXZ


	.global ?f606@_QIThunk@ATL@@UEAAJXZ
	.proc	?f606@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f606@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=606*8,r14	// r14 = &m_pUnk->vtbl[606] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[606]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[606].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[606].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f606@_QIThunk@ATL@@UEAAJXZ


	.global ?f607@_QIThunk@ATL@@UEAAJXZ
	.proc	?f607@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f607@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=607*8,r14	// r14 = &m_pUnk->vtbl[607] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[607]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[607].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[607].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f607@_QIThunk@ATL@@UEAAJXZ


	.global ?f608@_QIThunk@ATL@@UEAAJXZ
	.proc	?f608@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f608@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=608*8,r14	// r14 = &m_pUnk->vtbl[608] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[608]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[608].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[608].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f608@_QIThunk@ATL@@UEAAJXZ


	.global ?f609@_QIThunk@ATL@@UEAAJXZ
	.proc	?f609@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f609@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=609*8,r14	// r14 = &m_pUnk->vtbl[609] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[609]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[609].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[609].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f609@_QIThunk@ATL@@UEAAJXZ


	.global ?f610@_QIThunk@ATL@@UEAAJXZ
	.proc	?f610@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f610@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=610*8,r14	// r14 = &m_pUnk->vtbl[610] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[610]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[610].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[610].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f610@_QIThunk@ATL@@UEAAJXZ


	.global ?f611@_QIThunk@ATL@@UEAAJXZ
	.proc	?f611@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f611@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=611*8,r14	// r14 = &m_pUnk->vtbl[611] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[611]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[611].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[611].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f611@_QIThunk@ATL@@UEAAJXZ


	.global ?f612@_QIThunk@ATL@@UEAAJXZ
	.proc	?f612@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f612@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=612*8,r14	// r14 = &m_pUnk->vtbl[612] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[612]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[612].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[612].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f612@_QIThunk@ATL@@UEAAJXZ


	.global ?f613@_QIThunk@ATL@@UEAAJXZ
	.proc	?f613@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f613@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=613*8,r14	// r14 = &m_pUnk->vtbl[613] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[613]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[613].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[613].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f613@_QIThunk@ATL@@UEAAJXZ


	.global ?f614@_QIThunk@ATL@@UEAAJXZ
	.proc	?f614@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f614@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=614*8,r14	// r14 = &m_pUnk->vtbl[614] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[614]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[614].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[614].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f614@_QIThunk@ATL@@UEAAJXZ


	.global ?f615@_QIThunk@ATL@@UEAAJXZ
	.proc	?f615@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f615@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=615*8,r14	// r14 = &m_pUnk->vtbl[615] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[615]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[615].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[615].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f615@_QIThunk@ATL@@UEAAJXZ


	.global ?f616@_QIThunk@ATL@@UEAAJXZ
	.proc	?f616@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f616@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=616*8,r14	// r14 = &m_pUnk->vtbl[616] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[616]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[616].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[616].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f616@_QIThunk@ATL@@UEAAJXZ


	.global ?f617@_QIThunk@ATL@@UEAAJXZ
	.proc	?f617@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f617@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=617*8,r14	// r14 = &m_pUnk->vtbl[617] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[617]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[617].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[617].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f617@_QIThunk@ATL@@UEAAJXZ


	.global ?f618@_QIThunk@ATL@@UEAAJXZ
	.proc	?f618@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f618@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=618*8,r14	// r14 = &m_pUnk->vtbl[618] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[618]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[618].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[618].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f618@_QIThunk@ATL@@UEAAJXZ


	.global ?f619@_QIThunk@ATL@@UEAAJXZ
	.proc	?f619@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f619@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=619*8,r14	// r14 = &m_pUnk->vtbl[619] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[619]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[619].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[619].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f619@_QIThunk@ATL@@UEAAJXZ


	.global ?f620@_QIThunk@ATL@@UEAAJXZ
	.proc	?f620@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f620@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=620*8,r14	// r14 = &m_pUnk->vtbl[620] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[620]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[620].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[620].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f620@_QIThunk@ATL@@UEAAJXZ


	.global ?f621@_QIThunk@ATL@@UEAAJXZ
	.proc	?f621@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f621@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=621*8,r14	// r14 = &m_pUnk->vtbl[621] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[621]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[621].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[621].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f621@_QIThunk@ATL@@UEAAJXZ


	.global ?f622@_QIThunk@ATL@@UEAAJXZ
	.proc	?f622@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f622@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=622*8,r14	// r14 = &m_pUnk->vtbl[622] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[622]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[622].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[622].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f622@_QIThunk@ATL@@UEAAJXZ


	.global ?f623@_QIThunk@ATL@@UEAAJXZ
	.proc	?f623@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f623@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=623*8,r14	// r14 = &m_pUnk->vtbl[623] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[623]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[623].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[623].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f623@_QIThunk@ATL@@UEAAJXZ


	.global ?f624@_QIThunk@ATL@@UEAAJXZ
	.proc	?f624@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f624@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=624*8,r14	// r14 = &m_pUnk->vtbl[624] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[624]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[624].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[624].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f624@_QIThunk@ATL@@UEAAJXZ


	.global ?f625@_QIThunk@ATL@@UEAAJXZ
	.proc	?f625@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f625@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=625*8,r14	// r14 = &m_pUnk->vtbl[625] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[625]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[625].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[625].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f625@_QIThunk@ATL@@UEAAJXZ


	.global ?f626@_QIThunk@ATL@@UEAAJXZ
	.proc	?f626@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f626@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=626*8,r14	// r14 = &m_pUnk->vtbl[626] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[626]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[626].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[626].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f626@_QIThunk@ATL@@UEAAJXZ


	.global ?f627@_QIThunk@ATL@@UEAAJXZ
	.proc	?f627@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f627@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=627*8,r14	// r14 = &m_pUnk->vtbl[627] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[627]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[627].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[627].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f627@_QIThunk@ATL@@UEAAJXZ


	.global ?f628@_QIThunk@ATL@@UEAAJXZ
	.proc	?f628@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f628@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=628*8,r14	// r14 = &m_pUnk->vtbl[628] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[628]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[628].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[628].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f628@_QIThunk@ATL@@UEAAJXZ


	.global ?f629@_QIThunk@ATL@@UEAAJXZ
	.proc	?f629@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f629@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=629*8,r14	// r14 = &m_pUnk->vtbl[629] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[629]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[629].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[629].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f629@_QIThunk@ATL@@UEAAJXZ


	.global ?f630@_QIThunk@ATL@@UEAAJXZ
	.proc	?f630@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f630@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=630*8,r14	// r14 = &m_pUnk->vtbl[630] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[630]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[630].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[630].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f630@_QIThunk@ATL@@UEAAJXZ


	.global ?f631@_QIThunk@ATL@@UEAAJXZ
	.proc	?f631@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f631@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=631*8,r14	// r14 = &m_pUnk->vtbl[631] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[631]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[631].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[631].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f631@_QIThunk@ATL@@UEAAJXZ


	.global ?f632@_QIThunk@ATL@@UEAAJXZ
	.proc	?f632@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f632@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=632*8,r14	// r14 = &m_pUnk->vtbl[632] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[632]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[632].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[632].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f632@_QIThunk@ATL@@UEAAJXZ


	.global ?f633@_QIThunk@ATL@@UEAAJXZ
	.proc	?f633@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f633@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=633*8,r14	// r14 = &m_pUnk->vtbl[633] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[633]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[633].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[633].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f633@_QIThunk@ATL@@UEAAJXZ


	.global ?f634@_QIThunk@ATL@@UEAAJXZ
	.proc	?f634@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f634@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=634*8,r14	// r14 = &m_pUnk->vtbl[634] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[634]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[634].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[634].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f634@_QIThunk@ATL@@UEAAJXZ


	.global ?f635@_QIThunk@ATL@@UEAAJXZ
	.proc	?f635@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f635@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=635*8,r14	// r14 = &m_pUnk->vtbl[635] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[635]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[635].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[635].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f635@_QIThunk@ATL@@UEAAJXZ


	.global ?f636@_QIThunk@ATL@@UEAAJXZ
	.proc	?f636@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f636@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=636*8,r14	// r14 = &m_pUnk->vtbl[636] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[636]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[636].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[636].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f636@_QIThunk@ATL@@UEAAJXZ


	.global ?f637@_QIThunk@ATL@@UEAAJXZ
	.proc	?f637@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f637@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=637*8,r14	// r14 = &m_pUnk->vtbl[637] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[637]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[637].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[637].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f637@_QIThunk@ATL@@UEAAJXZ


	.global ?f638@_QIThunk@ATL@@UEAAJXZ
	.proc	?f638@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f638@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=638*8,r14	// r14 = &m_pUnk->vtbl[638] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[638]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[638].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[638].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f638@_QIThunk@ATL@@UEAAJXZ


	.global ?f639@_QIThunk@ATL@@UEAAJXZ
	.proc	?f639@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f639@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=639*8,r14	// r14 = &m_pUnk->vtbl[639] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[639]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[639].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[639].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f639@_QIThunk@ATL@@UEAAJXZ


	.global ?f640@_QIThunk@ATL@@UEAAJXZ
	.proc	?f640@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f640@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=640*8,r14	// r14 = &m_pUnk->vtbl[640] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[640]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[640].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[640].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f640@_QIThunk@ATL@@UEAAJXZ


	.global ?f641@_QIThunk@ATL@@UEAAJXZ
	.proc	?f641@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f641@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=641*8,r14	// r14 = &m_pUnk->vtbl[641] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[641]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[641].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[641].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f641@_QIThunk@ATL@@UEAAJXZ


	.global ?f642@_QIThunk@ATL@@UEAAJXZ
	.proc	?f642@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f642@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=642*8,r14	// r14 = &m_pUnk->vtbl[642] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[642]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[642].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[642].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f642@_QIThunk@ATL@@UEAAJXZ


	.global ?f643@_QIThunk@ATL@@UEAAJXZ
	.proc	?f643@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f643@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=643*8,r14	// r14 = &m_pUnk->vtbl[643] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[643]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[643].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[643].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f643@_QIThunk@ATL@@UEAAJXZ


	.global ?f644@_QIThunk@ATL@@UEAAJXZ
	.proc	?f644@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f644@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=644*8,r14	// r14 = &m_pUnk->vtbl[644] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[644]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[644].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[644].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f644@_QIThunk@ATL@@UEAAJXZ


	.global ?f645@_QIThunk@ATL@@UEAAJXZ
	.proc	?f645@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f645@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=645*8,r14	// r14 = &m_pUnk->vtbl[645] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[645]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[645].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[645].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f645@_QIThunk@ATL@@UEAAJXZ


	.global ?f646@_QIThunk@ATL@@UEAAJXZ
	.proc	?f646@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f646@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=646*8,r14	// r14 = &m_pUnk->vtbl[646] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[646]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[646].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[646].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f646@_QIThunk@ATL@@UEAAJXZ


	.global ?f647@_QIThunk@ATL@@UEAAJXZ
	.proc	?f647@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f647@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=647*8,r14	// r14 = &m_pUnk->vtbl[647] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[647]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[647].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[647].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f647@_QIThunk@ATL@@UEAAJXZ


	.global ?f648@_QIThunk@ATL@@UEAAJXZ
	.proc	?f648@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f648@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=648*8,r14	// r14 = &m_pUnk->vtbl[648] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[648]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[648].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[648].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f648@_QIThunk@ATL@@UEAAJXZ


	.global ?f649@_QIThunk@ATL@@UEAAJXZ
	.proc	?f649@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f649@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=649*8,r14	// r14 = &m_pUnk->vtbl[649] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[649]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[649].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[649].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f649@_QIThunk@ATL@@UEAAJXZ


	.global ?f650@_QIThunk@ATL@@UEAAJXZ
	.proc	?f650@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f650@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=650*8,r14	// r14 = &m_pUnk->vtbl[650] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[650]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[650].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[650].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f650@_QIThunk@ATL@@UEAAJXZ


	.global ?f651@_QIThunk@ATL@@UEAAJXZ
	.proc	?f651@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f651@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=651*8,r14	// r14 = &m_pUnk->vtbl[651] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[651]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[651].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[651].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f651@_QIThunk@ATL@@UEAAJXZ


	.global ?f652@_QIThunk@ATL@@UEAAJXZ
	.proc	?f652@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f652@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=652*8,r14	// r14 = &m_pUnk->vtbl[652] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[652]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[652].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[652].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f652@_QIThunk@ATL@@UEAAJXZ


	.global ?f653@_QIThunk@ATL@@UEAAJXZ
	.proc	?f653@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f653@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=653*8,r14	// r14 = &m_pUnk->vtbl[653] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[653]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[653].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[653].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f653@_QIThunk@ATL@@UEAAJXZ


	.global ?f654@_QIThunk@ATL@@UEAAJXZ
	.proc	?f654@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f654@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=654*8,r14	// r14 = &m_pUnk->vtbl[654] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[654]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[654].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[654].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f654@_QIThunk@ATL@@UEAAJXZ


	.global ?f655@_QIThunk@ATL@@UEAAJXZ
	.proc	?f655@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f655@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=655*8,r14	// r14 = &m_pUnk->vtbl[655] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[655]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[655].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[655].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f655@_QIThunk@ATL@@UEAAJXZ


	.global ?f656@_QIThunk@ATL@@UEAAJXZ
	.proc	?f656@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f656@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=656*8,r14	// r14 = &m_pUnk->vtbl[656] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[656]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[656].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[656].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f656@_QIThunk@ATL@@UEAAJXZ


	.global ?f657@_QIThunk@ATL@@UEAAJXZ
	.proc	?f657@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f657@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=657*8,r14	// r14 = &m_pUnk->vtbl[657] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[657]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[657].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[657].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f657@_QIThunk@ATL@@UEAAJXZ


	.global ?f658@_QIThunk@ATL@@UEAAJXZ
	.proc	?f658@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f658@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=658*8,r14	// r14 = &m_pUnk->vtbl[658] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[658]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[658].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[658].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f658@_QIThunk@ATL@@UEAAJXZ


	.global ?f659@_QIThunk@ATL@@UEAAJXZ
	.proc	?f659@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f659@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=659*8,r14	// r14 = &m_pUnk->vtbl[659] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[659]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[659].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[659].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f659@_QIThunk@ATL@@UEAAJXZ


	.global ?f660@_QIThunk@ATL@@UEAAJXZ
	.proc	?f660@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f660@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=660*8,r14	// r14 = &m_pUnk->vtbl[660] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[660]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[660].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[660].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f660@_QIThunk@ATL@@UEAAJXZ


	.global ?f661@_QIThunk@ATL@@UEAAJXZ
	.proc	?f661@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f661@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=661*8,r14	// r14 = &m_pUnk->vtbl[661] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[661]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[661].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[661].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f661@_QIThunk@ATL@@UEAAJXZ


	.global ?f662@_QIThunk@ATL@@UEAAJXZ
	.proc	?f662@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f662@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=662*8,r14	// r14 = &m_pUnk->vtbl[662] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[662]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[662].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[662].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f662@_QIThunk@ATL@@UEAAJXZ


	.global ?f663@_QIThunk@ATL@@UEAAJXZ
	.proc	?f663@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f663@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=663*8,r14	// r14 = &m_pUnk->vtbl[663] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[663]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[663].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[663].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f663@_QIThunk@ATL@@UEAAJXZ


	.global ?f664@_QIThunk@ATL@@UEAAJXZ
	.proc	?f664@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f664@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=664*8,r14	// r14 = &m_pUnk->vtbl[664] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[664]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[664].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[664].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f664@_QIThunk@ATL@@UEAAJXZ


	.global ?f665@_QIThunk@ATL@@UEAAJXZ
	.proc	?f665@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f665@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=665*8,r14	// r14 = &m_pUnk->vtbl[665] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[665]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[665].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[665].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f665@_QIThunk@ATL@@UEAAJXZ


	.global ?f666@_QIThunk@ATL@@UEAAJXZ
	.proc	?f666@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f666@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=666*8,r14	// r14 = &m_pUnk->vtbl[666] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[666]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[666].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[666].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f666@_QIThunk@ATL@@UEAAJXZ


	.global ?f667@_QIThunk@ATL@@UEAAJXZ
	.proc	?f667@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f667@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=667*8,r14	// r14 = &m_pUnk->vtbl[667] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[667]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[667].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[667].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f667@_QIThunk@ATL@@UEAAJXZ


	.global ?f668@_QIThunk@ATL@@UEAAJXZ
	.proc	?f668@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f668@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=668*8,r14	// r14 = &m_pUnk->vtbl[668] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[668]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[668].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[668].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f668@_QIThunk@ATL@@UEAAJXZ


	.global ?f669@_QIThunk@ATL@@UEAAJXZ
	.proc	?f669@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f669@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=669*8,r14	// r14 = &m_pUnk->vtbl[669] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[669]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[669].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[669].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f669@_QIThunk@ATL@@UEAAJXZ


	.global ?f670@_QIThunk@ATL@@UEAAJXZ
	.proc	?f670@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f670@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=670*8,r14	// r14 = &m_pUnk->vtbl[670] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[670]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[670].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[670].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f670@_QIThunk@ATL@@UEAAJXZ


	.global ?f671@_QIThunk@ATL@@UEAAJXZ
	.proc	?f671@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f671@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=671*8,r14	// r14 = &m_pUnk->vtbl[671] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[671]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[671].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[671].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f671@_QIThunk@ATL@@UEAAJXZ


	.global ?f672@_QIThunk@ATL@@UEAAJXZ
	.proc	?f672@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f672@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=672*8,r14	// r14 = &m_pUnk->vtbl[672] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[672]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[672].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[672].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f672@_QIThunk@ATL@@UEAAJXZ


	.global ?f673@_QIThunk@ATL@@UEAAJXZ
	.proc	?f673@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f673@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=673*8,r14	// r14 = &m_pUnk->vtbl[673] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[673]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[673].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[673].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f673@_QIThunk@ATL@@UEAAJXZ


	.global ?f674@_QIThunk@ATL@@UEAAJXZ
	.proc	?f674@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f674@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=674*8,r14	// r14 = &m_pUnk->vtbl[674] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[674]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[674].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[674].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f674@_QIThunk@ATL@@UEAAJXZ


	.global ?f675@_QIThunk@ATL@@UEAAJXZ
	.proc	?f675@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f675@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=675*8,r14	// r14 = &m_pUnk->vtbl[675] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[675]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[675].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[675].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f675@_QIThunk@ATL@@UEAAJXZ


	.global ?f676@_QIThunk@ATL@@UEAAJXZ
	.proc	?f676@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f676@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=676*8,r14	// r14 = &m_pUnk->vtbl[676] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[676]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[676].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[676].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f676@_QIThunk@ATL@@UEAAJXZ


	.global ?f677@_QIThunk@ATL@@UEAAJXZ
	.proc	?f677@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f677@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=677*8,r14	// r14 = &m_pUnk->vtbl[677] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[677]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[677].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[677].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f677@_QIThunk@ATL@@UEAAJXZ


	.global ?f678@_QIThunk@ATL@@UEAAJXZ
	.proc	?f678@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f678@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=678*8,r14	// r14 = &m_pUnk->vtbl[678] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[678]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[678].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[678].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f678@_QIThunk@ATL@@UEAAJXZ


	.global ?f679@_QIThunk@ATL@@UEAAJXZ
	.proc	?f679@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f679@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=679*8,r14	// r14 = &m_pUnk->vtbl[679] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[679]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[679].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[679].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f679@_QIThunk@ATL@@UEAAJXZ


	.global ?f680@_QIThunk@ATL@@UEAAJXZ
	.proc	?f680@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f680@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=680*8,r14	// r14 = &m_pUnk->vtbl[680] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[680]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[680].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[680].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f680@_QIThunk@ATL@@UEAAJXZ


	.global ?f681@_QIThunk@ATL@@UEAAJXZ
	.proc	?f681@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f681@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=681*8,r14	// r14 = &m_pUnk->vtbl[681] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[681]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[681].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[681].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f681@_QIThunk@ATL@@UEAAJXZ


	.global ?f682@_QIThunk@ATL@@UEAAJXZ
	.proc	?f682@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f682@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=682*8,r14	// r14 = &m_pUnk->vtbl[682] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[682]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[682].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[682].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f682@_QIThunk@ATL@@UEAAJXZ


	.global ?f683@_QIThunk@ATL@@UEAAJXZ
	.proc	?f683@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f683@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=683*8,r14	// r14 = &m_pUnk->vtbl[683] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[683]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[683].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[683].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f683@_QIThunk@ATL@@UEAAJXZ


	.global ?f684@_QIThunk@ATL@@UEAAJXZ
	.proc	?f684@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f684@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=684*8,r14	// r14 = &m_pUnk->vtbl[684] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[684]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[684].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[684].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f684@_QIThunk@ATL@@UEAAJXZ


	.global ?f685@_QIThunk@ATL@@UEAAJXZ
	.proc	?f685@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f685@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=685*8,r14	// r14 = &m_pUnk->vtbl[685] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[685]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[685].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[685].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f685@_QIThunk@ATL@@UEAAJXZ


	.global ?f686@_QIThunk@ATL@@UEAAJXZ
	.proc	?f686@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f686@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=686*8,r14	// r14 = &m_pUnk->vtbl[686] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[686]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[686].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[686].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f686@_QIThunk@ATL@@UEAAJXZ


	.global ?f687@_QIThunk@ATL@@UEAAJXZ
	.proc	?f687@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f687@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=687*8,r14	// r14 = &m_pUnk->vtbl[687] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[687]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[687].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[687].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f687@_QIThunk@ATL@@UEAAJXZ


	.global ?f688@_QIThunk@ATL@@UEAAJXZ
	.proc	?f688@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f688@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=688*8,r14	// r14 = &m_pUnk->vtbl[688] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[688]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[688].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[688].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f688@_QIThunk@ATL@@UEAAJXZ


	.global ?f689@_QIThunk@ATL@@UEAAJXZ
	.proc	?f689@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f689@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=689*8,r14	// r14 = &m_pUnk->vtbl[689] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[689]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[689].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[689].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f689@_QIThunk@ATL@@UEAAJXZ


	.global ?f690@_QIThunk@ATL@@UEAAJXZ
	.proc	?f690@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f690@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=690*8,r14	// r14 = &m_pUnk->vtbl[690] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[690]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[690].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[690].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f690@_QIThunk@ATL@@UEAAJXZ


	.global ?f691@_QIThunk@ATL@@UEAAJXZ
	.proc	?f691@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f691@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=691*8,r14	// r14 = &m_pUnk->vtbl[691] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[691]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[691].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[691].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f691@_QIThunk@ATL@@UEAAJXZ


	.global ?f692@_QIThunk@ATL@@UEAAJXZ
	.proc	?f692@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f692@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=692*8,r14	// r14 = &m_pUnk->vtbl[692] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[692]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[692].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[692].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f692@_QIThunk@ATL@@UEAAJXZ


	.global ?f693@_QIThunk@ATL@@UEAAJXZ
	.proc	?f693@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f693@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=693*8,r14	// r14 = &m_pUnk->vtbl[693] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[693]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[693].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[693].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f693@_QIThunk@ATL@@UEAAJXZ


	.global ?f694@_QIThunk@ATL@@UEAAJXZ
	.proc	?f694@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f694@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=694*8,r14	// r14 = &m_pUnk->vtbl[694] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[694]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[694].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[694].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f694@_QIThunk@ATL@@UEAAJXZ


	.global ?f695@_QIThunk@ATL@@UEAAJXZ
	.proc	?f695@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f695@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=695*8,r14	// r14 = &m_pUnk->vtbl[695] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[695]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[695].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[695].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f695@_QIThunk@ATL@@UEAAJXZ


	.global ?f696@_QIThunk@ATL@@UEAAJXZ
	.proc	?f696@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f696@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=696*8,r14	// r14 = &m_pUnk->vtbl[696] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[696]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[696].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[696].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f696@_QIThunk@ATL@@UEAAJXZ


	.global ?f697@_QIThunk@ATL@@UEAAJXZ
	.proc	?f697@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f697@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=697*8,r14	// r14 = &m_pUnk->vtbl[697] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[697]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[697].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[697].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f697@_QIThunk@ATL@@UEAAJXZ


	.global ?f698@_QIThunk@ATL@@UEAAJXZ
	.proc	?f698@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f698@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=698*8,r14	// r14 = &m_pUnk->vtbl[698] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[698]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[698].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[698].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f698@_QIThunk@ATL@@UEAAJXZ


	.global ?f699@_QIThunk@ATL@@UEAAJXZ
	.proc	?f699@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f699@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=699*8,r14	// r14 = &m_pUnk->vtbl[699] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[699]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[699].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[699].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f699@_QIThunk@ATL@@UEAAJXZ


	.global ?f700@_QIThunk@ATL@@UEAAJXZ
	.proc	?f700@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f700@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=700*8,r14	// r14 = &m_pUnk->vtbl[700] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[700]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[700].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[700].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f700@_QIThunk@ATL@@UEAAJXZ


	.global ?f701@_QIThunk@ATL@@UEAAJXZ
	.proc	?f701@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f701@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=701*8,r14	// r14 = &m_pUnk->vtbl[701] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[701]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[701].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[701].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f701@_QIThunk@ATL@@UEAAJXZ


	.global ?f702@_QIThunk@ATL@@UEAAJXZ
	.proc	?f702@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f702@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=702*8,r14	// r14 = &m_pUnk->vtbl[702] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[702]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[702].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[702].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f702@_QIThunk@ATL@@UEAAJXZ


	.global ?f703@_QIThunk@ATL@@UEAAJXZ
	.proc	?f703@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f703@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=703*8,r14	// r14 = &m_pUnk->vtbl[703] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[703]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[703].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[703].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f703@_QIThunk@ATL@@UEAAJXZ


	.global ?f704@_QIThunk@ATL@@UEAAJXZ
	.proc	?f704@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f704@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=704*8,r14	// r14 = &m_pUnk->vtbl[704] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[704]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[704].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[704].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f704@_QIThunk@ATL@@UEAAJXZ


	.global ?f705@_QIThunk@ATL@@UEAAJXZ
	.proc	?f705@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f705@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=705*8,r14	// r14 = &m_pUnk->vtbl[705] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[705]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[705].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[705].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f705@_QIThunk@ATL@@UEAAJXZ


	.global ?f706@_QIThunk@ATL@@UEAAJXZ
	.proc	?f706@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f706@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=706*8,r14	// r14 = &m_pUnk->vtbl[706] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[706]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[706].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[706].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f706@_QIThunk@ATL@@UEAAJXZ


	.global ?f707@_QIThunk@ATL@@UEAAJXZ
	.proc	?f707@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f707@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=707*8,r14	// r14 = &m_pUnk->vtbl[707] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[707]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[707].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[707].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f707@_QIThunk@ATL@@UEAAJXZ


	.global ?f708@_QIThunk@ATL@@UEAAJXZ
	.proc	?f708@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f708@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=708*8,r14	// r14 = &m_pUnk->vtbl[708] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[708]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[708].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[708].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f708@_QIThunk@ATL@@UEAAJXZ


	.global ?f709@_QIThunk@ATL@@UEAAJXZ
	.proc	?f709@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f709@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=709*8,r14	// r14 = &m_pUnk->vtbl[709] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[709]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[709].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[709].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f709@_QIThunk@ATL@@UEAAJXZ


	.global ?f710@_QIThunk@ATL@@UEAAJXZ
	.proc	?f710@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f710@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=710*8,r14	// r14 = &m_pUnk->vtbl[710] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[710]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[710].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[710].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f710@_QIThunk@ATL@@UEAAJXZ


	.global ?f711@_QIThunk@ATL@@UEAAJXZ
	.proc	?f711@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f711@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=711*8,r14	// r14 = &m_pUnk->vtbl[711] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[711]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[711].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[711].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f711@_QIThunk@ATL@@UEAAJXZ


	.global ?f712@_QIThunk@ATL@@UEAAJXZ
	.proc	?f712@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f712@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=712*8,r14	// r14 = &m_pUnk->vtbl[712] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[712]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[712].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[712].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f712@_QIThunk@ATL@@UEAAJXZ


	.global ?f713@_QIThunk@ATL@@UEAAJXZ
	.proc	?f713@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f713@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=713*8,r14	// r14 = &m_pUnk->vtbl[713] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[713]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[713].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[713].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f713@_QIThunk@ATL@@UEAAJXZ


	.global ?f714@_QIThunk@ATL@@UEAAJXZ
	.proc	?f714@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f714@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=714*8,r14	// r14 = &m_pUnk->vtbl[714] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[714]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[714].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[714].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f714@_QIThunk@ATL@@UEAAJXZ


	.global ?f715@_QIThunk@ATL@@UEAAJXZ
	.proc	?f715@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f715@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=715*8,r14	// r14 = &m_pUnk->vtbl[715] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[715]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[715].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[715].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f715@_QIThunk@ATL@@UEAAJXZ


	.global ?f716@_QIThunk@ATL@@UEAAJXZ
	.proc	?f716@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f716@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=716*8,r14	// r14 = &m_pUnk->vtbl[716] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[716]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[716].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[716].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f716@_QIThunk@ATL@@UEAAJXZ


	.global ?f717@_QIThunk@ATL@@UEAAJXZ
	.proc	?f717@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f717@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=717*8,r14	// r14 = &m_pUnk->vtbl[717] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[717]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[717].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[717].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f717@_QIThunk@ATL@@UEAAJXZ


	.global ?f718@_QIThunk@ATL@@UEAAJXZ
	.proc	?f718@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f718@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=718*8,r14	// r14 = &m_pUnk->vtbl[718] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[718]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[718].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[718].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f718@_QIThunk@ATL@@UEAAJXZ


	.global ?f719@_QIThunk@ATL@@UEAAJXZ
	.proc	?f719@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f719@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=719*8,r14	// r14 = &m_pUnk->vtbl[719] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[719]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[719].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[719].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f719@_QIThunk@ATL@@UEAAJXZ


	.global ?f720@_QIThunk@ATL@@UEAAJXZ
	.proc	?f720@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f720@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=720*8,r14	// r14 = &m_pUnk->vtbl[720] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[720]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[720].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[720].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f720@_QIThunk@ATL@@UEAAJXZ


	.global ?f721@_QIThunk@ATL@@UEAAJXZ
	.proc	?f721@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f721@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=721*8,r14	// r14 = &m_pUnk->vtbl[721] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[721]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[721].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[721].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f721@_QIThunk@ATL@@UEAAJXZ


	.global ?f722@_QIThunk@ATL@@UEAAJXZ
	.proc	?f722@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f722@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=722*8,r14	// r14 = &m_pUnk->vtbl[722] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[722]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[722].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[722].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f722@_QIThunk@ATL@@UEAAJXZ


	.global ?f723@_QIThunk@ATL@@UEAAJXZ
	.proc	?f723@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f723@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=723*8,r14	// r14 = &m_pUnk->vtbl[723] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[723]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[723].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[723].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f723@_QIThunk@ATL@@UEAAJXZ


	.global ?f724@_QIThunk@ATL@@UEAAJXZ
	.proc	?f724@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f724@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=724*8,r14	// r14 = &m_pUnk->vtbl[724] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[724]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[724].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[724].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f724@_QIThunk@ATL@@UEAAJXZ


	.global ?f725@_QIThunk@ATL@@UEAAJXZ
	.proc	?f725@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f725@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=725*8,r14	// r14 = &m_pUnk->vtbl[725] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[725]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[725].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[725].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f725@_QIThunk@ATL@@UEAAJXZ


	.global ?f726@_QIThunk@ATL@@UEAAJXZ
	.proc	?f726@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f726@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=726*8,r14	// r14 = &m_pUnk->vtbl[726] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[726]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[726].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[726].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f726@_QIThunk@ATL@@UEAAJXZ


	.global ?f727@_QIThunk@ATL@@UEAAJXZ
	.proc	?f727@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f727@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=727*8,r14	// r14 = &m_pUnk->vtbl[727] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[727]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[727].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[727].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f727@_QIThunk@ATL@@UEAAJXZ


	.global ?f728@_QIThunk@ATL@@UEAAJXZ
	.proc	?f728@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f728@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=728*8,r14	// r14 = &m_pUnk->vtbl[728] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[728]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[728].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[728].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f728@_QIThunk@ATL@@UEAAJXZ


	.global ?f729@_QIThunk@ATL@@UEAAJXZ
	.proc	?f729@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f729@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=729*8,r14	// r14 = &m_pUnk->vtbl[729] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[729]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[729].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[729].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f729@_QIThunk@ATL@@UEAAJXZ


	.global ?f730@_QIThunk@ATL@@UEAAJXZ
	.proc	?f730@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f730@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=730*8,r14	// r14 = &m_pUnk->vtbl[730] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[730]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[730].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[730].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f730@_QIThunk@ATL@@UEAAJXZ


	.global ?f731@_QIThunk@ATL@@UEAAJXZ
	.proc	?f731@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f731@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=731*8,r14	// r14 = &m_pUnk->vtbl[731] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[731]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[731].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[731].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f731@_QIThunk@ATL@@UEAAJXZ


	.global ?f732@_QIThunk@ATL@@UEAAJXZ
	.proc	?f732@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f732@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=732*8,r14	// r14 = &m_pUnk->vtbl[732] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[732]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[732].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[732].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f732@_QIThunk@ATL@@UEAAJXZ


	.global ?f733@_QIThunk@ATL@@UEAAJXZ
	.proc	?f733@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f733@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=733*8,r14	// r14 = &m_pUnk->vtbl[733] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[733]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[733].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[733].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f733@_QIThunk@ATL@@UEAAJXZ


	.global ?f734@_QIThunk@ATL@@UEAAJXZ
	.proc	?f734@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f734@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=734*8,r14	// r14 = &m_pUnk->vtbl[734] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[734]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[734].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[734].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f734@_QIThunk@ATL@@UEAAJXZ


	.global ?f735@_QIThunk@ATL@@UEAAJXZ
	.proc	?f735@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f735@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=735*8,r14	// r14 = &m_pUnk->vtbl[735] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[735]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[735].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[735].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f735@_QIThunk@ATL@@UEAAJXZ


	.global ?f736@_QIThunk@ATL@@UEAAJXZ
	.proc	?f736@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f736@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=736*8,r14	// r14 = &m_pUnk->vtbl[736] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[736]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[736].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[736].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f736@_QIThunk@ATL@@UEAAJXZ


	.global ?f737@_QIThunk@ATL@@UEAAJXZ
	.proc	?f737@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f737@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=737*8,r14	// r14 = &m_pUnk->vtbl[737] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[737]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[737].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[737].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f737@_QIThunk@ATL@@UEAAJXZ


	.global ?f738@_QIThunk@ATL@@UEAAJXZ
	.proc	?f738@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f738@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=738*8,r14	// r14 = &m_pUnk->vtbl[738] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[738]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[738].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[738].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f738@_QIThunk@ATL@@UEAAJXZ


	.global ?f739@_QIThunk@ATL@@UEAAJXZ
	.proc	?f739@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f739@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=739*8,r14	// r14 = &m_pUnk->vtbl[739] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[739]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[739].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[739].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f739@_QIThunk@ATL@@UEAAJXZ


	.global ?f740@_QIThunk@ATL@@UEAAJXZ
	.proc	?f740@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f740@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=740*8,r14	// r14 = &m_pUnk->vtbl[740] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[740]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[740].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[740].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f740@_QIThunk@ATL@@UEAAJXZ


	.global ?f741@_QIThunk@ATL@@UEAAJXZ
	.proc	?f741@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f741@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=741*8,r14	// r14 = &m_pUnk->vtbl[741] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[741]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[741].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[741].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f741@_QIThunk@ATL@@UEAAJXZ


	.global ?f742@_QIThunk@ATL@@UEAAJXZ
	.proc	?f742@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f742@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=742*8,r14	// r14 = &m_pUnk->vtbl[742] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[742]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[742].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[742].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f742@_QIThunk@ATL@@UEAAJXZ


	.global ?f743@_QIThunk@ATL@@UEAAJXZ
	.proc	?f743@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f743@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=743*8,r14	// r14 = &m_pUnk->vtbl[743] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[743]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[743].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[743].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f743@_QIThunk@ATL@@UEAAJXZ


	.global ?f744@_QIThunk@ATL@@UEAAJXZ
	.proc	?f744@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f744@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=744*8,r14	// r14 = &m_pUnk->vtbl[744] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[744]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[744].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[744].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f744@_QIThunk@ATL@@UEAAJXZ


	.global ?f745@_QIThunk@ATL@@UEAAJXZ
	.proc	?f745@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f745@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=745*8,r14	// r14 = &m_pUnk->vtbl[745] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[745]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[745].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[745].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f745@_QIThunk@ATL@@UEAAJXZ


	.global ?f746@_QIThunk@ATL@@UEAAJXZ
	.proc	?f746@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f746@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=746*8,r14	// r14 = &m_pUnk->vtbl[746] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[746]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[746].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[746].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f746@_QIThunk@ATL@@UEAAJXZ


	.global ?f747@_QIThunk@ATL@@UEAAJXZ
	.proc	?f747@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f747@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=747*8,r14	// r14 = &m_pUnk->vtbl[747] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[747]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[747].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[747].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f747@_QIThunk@ATL@@UEAAJXZ


	.global ?f748@_QIThunk@ATL@@UEAAJXZ
	.proc	?f748@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f748@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=748*8,r14	// r14 = &m_pUnk->vtbl[748] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[748]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[748].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[748].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f748@_QIThunk@ATL@@UEAAJXZ


	.global ?f749@_QIThunk@ATL@@UEAAJXZ
	.proc	?f749@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f749@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=749*8,r14	// r14 = &m_pUnk->vtbl[749] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[749]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[749].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[749].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f749@_QIThunk@ATL@@UEAAJXZ


	.global ?f750@_QIThunk@ATL@@UEAAJXZ
	.proc	?f750@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f750@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=750*8,r14	// r14 = &m_pUnk->vtbl[750] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[750]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[750].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[750].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f750@_QIThunk@ATL@@UEAAJXZ


	.global ?f751@_QIThunk@ATL@@UEAAJXZ
	.proc	?f751@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f751@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=751*8,r14	// r14 = &m_pUnk->vtbl[751] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[751]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[751].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[751].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f751@_QIThunk@ATL@@UEAAJXZ


	.global ?f752@_QIThunk@ATL@@UEAAJXZ
	.proc	?f752@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f752@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=752*8,r14	// r14 = &m_pUnk->vtbl[752] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[752]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[752].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[752].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f752@_QIThunk@ATL@@UEAAJXZ


	.global ?f753@_QIThunk@ATL@@UEAAJXZ
	.proc	?f753@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f753@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=753*8,r14	// r14 = &m_pUnk->vtbl[753] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[753]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[753].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[753].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f753@_QIThunk@ATL@@UEAAJXZ


	.global ?f754@_QIThunk@ATL@@UEAAJXZ
	.proc	?f754@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f754@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=754*8,r14	// r14 = &m_pUnk->vtbl[754] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[754]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[754].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[754].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f754@_QIThunk@ATL@@UEAAJXZ


	.global ?f755@_QIThunk@ATL@@UEAAJXZ
	.proc	?f755@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f755@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=755*8,r14	// r14 = &m_pUnk->vtbl[755] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[755]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[755].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[755].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f755@_QIThunk@ATL@@UEAAJXZ


	.global ?f756@_QIThunk@ATL@@UEAAJXZ
	.proc	?f756@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f756@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=756*8,r14	// r14 = &m_pUnk->vtbl[756] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[756]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[756].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[756].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f756@_QIThunk@ATL@@UEAAJXZ


	.global ?f757@_QIThunk@ATL@@UEAAJXZ
	.proc	?f757@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f757@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=757*8,r14	// r14 = &m_pUnk->vtbl[757] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[757]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[757].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[757].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f757@_QIThunk@ATL@@UEAAJXZ


	.global ?f758@_QIThunk@ATL@@UEAAJXZ
	.proc	?f758@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f758@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=758*8,r14	// r14 = &m_pUnk->vtbl[758] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[758]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[758].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[758].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f758@_QIThunk@ATL@@UEAAJXZ


	.global ?f759@_QIThunk@ATL@@UEAAJXZ
	.proc	?f759@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f759@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=759*8,r14	// r14 = &m_pUnk->vtbl[759] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[759]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[759].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[759].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f759@_QIThunk@ATL@@UEAAJXZ


	.global ?f760@_QIThunk@ATL@@UEAAJXZ
	.proc	?f760@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f760@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=760*8,r14	// r14 = &m_pUnk->vtbl[760] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[760]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[760].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[760].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f760@_QIThunk@ATL@@UEAAJXZ


	.global ?f761@_QIThunk@ATL@@UEAAJXZ
	.proc	?f761@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f761@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=761*8,r14	// r14 = &m_pUnk->vtbl[761] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[761]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[761].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[761].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f761@_QIThunk@ATL@@UEAAJXZ


	.global ?f762@_QIThunk@ATL@@UEAAJXZ
	.proc	?f762@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f762@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=762*8,r14	// r14 = &m_pUnk->vtbl[762] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[762]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[762].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[762].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f762@_QIThunk@ATL@@UEAAJXZ


	.global ?f763@_QIThunk@ATL@@UEAAJXZ
	.proc	?f763@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f763@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=763*8,r14	// r14 = &m_pUnk->vtbl[763] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[763]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[763].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[763].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f763@_QIThunk@ATL@@UEAAJXZ


	.global ?f764@_QIThunk@ATL@@UEAAJXZ
	.proc	?f764@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f764@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=764*8,r14	// r14 = &m_pUnk->vtbl[764] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[764]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[764].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[764].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f764@_QIThunk@ATL@@UEAAJXZ


	.global ?f765@_QIThunk@ATL@@UEAAJXZ
	.proc	?f765@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f765@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=765*8,r14	// r14 = &m_pUnk->vtbl[765] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[765]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[765].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[765].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f765@_QIThunk@ATL@@UEAAJXZ


	.global ?f766@_QIThunk@ATL@@UEAAJXZ
	.proc	?f766@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f766@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=766*8,r14	// r14 = &m_pUnk->vtbl[766] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[766]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[766].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[766].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f766@_QIThunk@ATL@@UEAAJXZ


	.global ?f767@_QIThunk@ATL@@UEAAJXZ
	.proc	?f767@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f767@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=767*8,r14	// r14 = &m_pUnk->vtbl[767] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[767]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[767].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[767].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f767@_QIThunk@ATL@@UEAAJXZ


	.global ?f768@_QIThunk@ATL@@UEAAJXZ
	.proc	?f768@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f768@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=768*8,r14	// r14 = &m_pUnk->vtbl[768] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[768]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[768].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[768].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f768@_QIThunk@ATL@@UEAAJXZ


	.global ?f769@_QIThunk@ATL@@UEAAJXZ
	.proc	?f769@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f769@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=769*8,r14	// r14 = &m_pUnk->vtbl[769] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[769]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[769].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[769].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f769@_QIThunk@ATL@@UEAAJXZ


	.global ?f770@_QIThunk@ATL@@UEAAJXZ
	.proc	?f770@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f770@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=770*8,r14	// r14 = &m_pUnk->vtbl[770] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[770]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[770].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[770].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f770@_QIThunk@ATL@@UEAAJXZ


	.global ?f771@_QIThunk@ATL@@UEAAJXZ
	.proc	?f771@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f771@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=771*8,r14	// r14 = &m_pUnk->vtbl[771] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[771]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[771].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[771].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f771@_QIThunk@ATL@@UEAAJXZ


	.global ?f772@_QIThunk@ATL@@UEAAJXZ
	.proc	?f772@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f772@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=772*8,r14	// r14 = &m_pUnk->vtbl[772] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[772]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[772].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[772].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f772@_QIThunk@ATL@@UEAAJXZ


	.global ?f773@_QIThunk@ATL@@UEAAJXZ
	.proc	?f773@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f773@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=773*8,r14	// r14 = &m_pUnk->vtbl[773] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[773]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[773].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[773].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f773@_QIThunk@ATL@@UEAAJXZ


	.global ?f774@_QIThunk@ATL@@UEAAJXZ
	.proc	?f774@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f774@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=774*8,r14	// r14 = &m_pUnk->vtbl[774] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[774]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[774].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[774].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f774@_QIThunk@ATL@@UEAAJXZ


	.global ?f775@_QIThunk@ATL@@UEAAJXZ
	.proc	?f775@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f775@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=775*8,r14	// r14 = &m_pUnk->vtbl[775] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[775]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[775].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[775].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f775@_QIThunk@ATL@@UEAAJXZ


	.global ?f776@_QIThunk@ATL@@UEAAJXZ
	.proc	?f776@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f776@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=776*8,r14	// r14 = &m_pUnk->vtbl[776] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[776]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[776].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[776].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f776@_QIThunk@ATL@@UEAAJXZ


	.global ?f777@_QIThunk@ATL@@UEAAJXZ
	.proc	?f777@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f777@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=777*8,r14	// r14 = &m_pUnk->vtbl[777] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[777]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[777].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[777].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f777@_QIThunk@ATL@@UEAAJXZ


	.global ?f778@_QIThunk@ATL@@UEAAJXZ
	.proc	?f778@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f778@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=778*8,r14	// r14 = &m_pUnk->vtbl[778] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[778]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[778].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[778].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f778@_QIThunk@ATL@@UEAAJXZ


	.global ?f779@_QIThunk@ATL@@UEAAJXZ
	.proc	?f779@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f779@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=779*8,r14	// r14 = &m_pUnk->vtbl[779] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[779]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[779].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[779].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f779@_QIThunk@ATL@@UEAAJXZ


	.global ?f780@_QIThunk@ATL@@UEAAJXZ
	.proc	?f780@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f780@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=780*8,r14	// r14 = &m_pUnk->vtbl[780] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[780]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[780].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[780].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f780@_QIThunk@ATL@@UEAAJXZ


	.global ?f781@_QIThunk@ATL@@UEAAJXZ
	.proc	?f781@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f781@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=781*8,r14	// r14 = &m_pUnk->vtbl[781] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[781]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[781].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[781].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f781@_QIThunk@ATL@@UEAAJXZ


	.global ?f782@_QIThunk@ATL@@UEAAJXZ
	.proc	?f782@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f782@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=782*8,r14	// r14 = &m_pUnk->vtbl[782] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[782]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[782].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[782].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f782@_QIThunk@ATL@@UEAAJXZ


	.global ?f783@_QIThunk@ATL@@UEAAJXZ
	.proc	?f783@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f783@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=783*8,r14	// r14 = &m_pUnk->vtbl[783] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[783]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[783].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[783].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f783@_QIThunk@ATL@@UEAAJXZ


	.global ?f784@_QIThunk@ATL@@UEAAJXZ
	.proc	?f784@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f784@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=784*8,r14	// r14 = &m_pUnk->vtbl[784] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[784]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[784].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[784].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f784@_QIThunk@ATL@@UEAAJXZ


	.global ?f785@_QIThunk@ATL@@UEAAJXZ
	.proc	?f785@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f785@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=785*8,r14	// r14 = &m_pUnk->vtbl[785] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[785]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[785].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[785].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f785@_QIThunk@ATL@@UEAAJXZ


	.global ?f786@_QIThunk@ATL@@UEAAJXZ
	.proc	?f786@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f786@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=786*8,r14	// r14 = &m_pUnk->vtbl[786] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[786]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[786].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[786].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f786@_QIThunk@ATL@@UEAAJXZ


	.global ?f787@_QIThunk@ATL@@UEAAJXZ
	.proc	?f787@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f787@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=787*8,r14	// r14 = &m_pUnk->vtbl[787] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[787]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[787].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[787].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f787@_QIThunk@ATL@@UEAAJXZ


	.global ?f788@_QIThunk@ATL@@UEAAJXZ
	.proc	?f788@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f788@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=788*8,r14	// r14 = &m_pUnk->vtbl[788] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[788]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[788].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[788].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f788@_QIThunk@ATL@@UEAAJXZ


	.global ?f789@_QIThunk@ATL@@UEAAJXZ
	.proc	?f789@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f789@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=789*8,r14	// r14 = &m_pUnk->vtbl[789] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[789]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[789].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[789].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f789@_QIThunk@ATL@@UEAAJXZ


	.global ?f790@_QIThunk@ATL@@UEAAJXZ
	.proc	?f790@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f790@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=790*8,r14	// r14 = &m_pUnk->vtbl[790] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[790]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[790].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[790].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f790@_QIThunk@ATL@@UEAAJXZ


	.global ?f791@_QIThunk@ATL@@UEAAJXZ
	.proc	?f791@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f791@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=791*8,r14	// r14 = &m_pUnk->vtbl[791] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[791]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[791].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[791].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f791@_QIThunk@ATL@@UEAAJXZ


	.global ?f792@_QIThunk@ATL@@UEAAJXZ
	.proc	?f792@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f792@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=792*8,r14	// r14 = &m_pUnk->vtbl[792] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[792]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[792].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[792].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f792@_QIThunk@ATL@@UEAAJXZ


	.global ?f793@_QIThunk@ATL@@UEAAJXZ
	.proc	?f793@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f793@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=793*8,r14	// r14 = &m_pUnk->vtbl[793] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[793]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[793].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[793].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f793@_QIThunk@ATL@@UEAAJXZ


	.global ?f794@_QIThunk@ATL@@UEAAJXZ
	.proc	?f794@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f794@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=794*8,r14	// r14 = &m_pUnk->vtbl[794] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[794]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[794].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[794].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f794@_QIThunk@ATL@@UEAAJXZ


	.global ?f795@_QIThunk@ATL@@UEAAJXZ
	.proc	?f795@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f795@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=795*8,r14	// r14 = &m_pUnk->vtbl[795] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[795]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[795].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[795].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f795@_QIThunk@ATL@@UEAAJXZ


	.global ?f796@_QIThunk@ATL@@UEAAJXZ
	.proc	?f796@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f796@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=796*8,r14	// r14 = &m_pUnk->vtbl[796] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[796]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[796].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[796].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f796@_QIThunk@ATL@@UEAAJXZ


	.global ?f797@_QIThunk@ATL@@UEAAJXZ
	.proc	?f797@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f797@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=797*8,r14	// r14 = &m_pUnk->vtbl[797] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[797]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[797].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[797].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f797@_QIThunk@ATL@@UEAAJXZ


	.global ?f798@_QIThunk@ATL@@UEAAJXZ
	.proc	?f798@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f798@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=798*8,r14	// r14 = &m_pUnk->vtbl[798] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[798]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[798].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[798].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f798@_QIThunk@ATL@@UEAAJXZ


	.global ?f799@_QIThunk@ATL@@UEAAJXZ
	.proc	?f799@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f799@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=799*8,r14	// r14 = &m_pUnk->vtbl[799] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[799]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[799].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[799].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f799@_QIThunk@ATL@@UEAAJXZ


	.global ?f800@_QIThunk@ATL@@UEAAJXZ
	.proc	?f800@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f800@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=800*8,r14	// r14 = &m_pUnk->vtbl[800] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[800]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[800].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[800].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f800@_QIThunk@ATL@@UEAAJXZ


	.global ?f801@_QIThunk@ATL@@UEAAJXZ
	.proc	?f801@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f801@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=801*8,r14	// r14 = &m_pUnk->vtbl[801] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[801]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[801].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[801].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f801@_QIThunk@ATL@@UEAAJXZ


	.global ?f802@_QIThunk@ATL@@UEAAJXZ
	.proc	?f802@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f802@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=802*8,r14	// r14 = &m_pUnk->vtbl[802] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[802]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[802].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[802].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f802@_QIThunk@ATL@@UEAAJXZ


	.global ?f803@_QIThunk@ATL@@UEAAJXZ
	.proc	?f803@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f803@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=803*8,r14	// r14 = &m_pUnk->vtbl[803] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[803]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[803].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[803].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f803@_QIThunk@ATL@@UEAAJXZ


	.global ?f804@_QIThunk@ATL@@UEAAJXZ
	.proc	?f804@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f804@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=804*8,r14	// r14 = &m_pUnk->vtbl[804] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[804]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[804].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[804].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f804@_QIThunk@ATL@@UEAAJXZ


	.global ?f805@_QIThunk@ATL@@UEAAJXZ
	.proc	?f805@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f805@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=805*8,r14	// r14 = &m_pUnk->vtbl[805] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[805]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[805].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[805].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f805@_QIThunk@ATL@@UEAAJXZ


	.global ?f806@_QIThunk@ATL@@UEAAJXZ
	.proc	?f806@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f806@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=806*8,r14	// r14 = &m_pUnk->vtbl[806] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[806]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[806].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[806].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f806@_QIThunk@ATL@@UEAAJXZ


	.global ?f807@_QIThunk@ATL@@UEAAJXZ
	.proc	?f807@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f807@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=807*8,r14	// r14 = &m_pUnk->vtbl[807] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[807]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[807].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[807].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f807@_QIThunk@ATL@@UEAAJXZ


	.global ?f808@_QIThunk@ATL@@UEAAJXZ
	.proc	?f808@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f808@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=808*8,r14	// r14 = &m_pUnk->vtbl[808] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[808]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[808].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[808].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f808@_QIThunk@ATL@@UEAAJXZ


	.global ?f809@_QIThunk@ATL@@UEAAJXZ
	.proc	?f809@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f809@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=809*8,r14	// r14 = &m_pUnk->vtbl[809] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[809]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[809].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[809].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f809@_QIThunk@ATL@@UEAAJXZ


	.global ?f810@_QIThunk@ATL@@UEAAJXZ
	.proc	?f810@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f810@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=810*8,r14	// r14 = &m_pUnk->vtbl[810] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[810]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[810].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[810].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f810@_QIThunk@ATL@@UEAAJXZ


	.global ?f811@_QIThunk@ATL@@UEAAJXZ
	.proc	?f811@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f811@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=811*8,r14	// r14 = &m_pUnk->vtbl[811] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[811]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[811].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[811].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f811@_QIThunk@ATL@@UEAAJXZ


	.global ?f812@_QIThunk@ATL@@UEAAJXZ
	.proc	?f812@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f812@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=812*8,r14	// r14 = &m_pUnk->vtbl[812] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[812]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[812].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[812].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f812@_QIThunk@ATL@@UEAAJXZ


	.global ?f813@_QIThunk@ATL@@UEAAJXZ
	.proc	?f813@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f813@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=813*8,r14	// r14 = &m_pUnk->vtbl[813] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[813]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[813].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[813].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f813@_QIThunk@ATL@@UEAAJXZ


	.global ?f814@_QIThunk@ATL@@UEAAJXZ
	.proc	?f814@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f814@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=814*8,r14	// r14 = &m_pUnk->vtbl[814] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[814]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[814].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[814].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f814@_QIThunk@ATL@@UEAAJXZ


	.global ?f815@_QIThunk@ATL@@UEAAJXZ
	.proc	?f815@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f815@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=815*8,r14	// r14 = &m_pUnk->vtbl[815] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[815]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[815].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[815].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f815@_QIThunk@ATL@@UEAAJXZ


	.global ?f816@_QIThunk@ATL@@UEAAJXZ
	.proc	?f816@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f816@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=816*8,r14	// r14 = &m_pUnk->vtbl[816] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[816]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[816].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[816].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f816@_QIThunk@ATL@@UEAAJXZ


	.global ?f817@_QIThunk@ATL@@UEAAJXZ
	.proc	?f817@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f817@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=817*8,r14	// r14 = &m_pUnk->vtbl[817] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[817]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[817].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[817].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f817@_QIThunk@ATL@@UEAAJXZ


	.global ?f818@_QIThunk@ATL@@UEAAJXZ
	.proc	?f818@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f818@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=818*8,r14	// r14 = &m_pUnk->vtbl[818] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[818]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[818].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[818].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f818@_QIThunk@ATL@@UEAAJXZ


	.global ?f819@_QIThunk@ATL@@UEAAJXZ
	.proc	?f819@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f819@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=819*8,r14	// r14 = &m_pUnk->vtbl[819] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[819]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[819].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[819].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f819@_QIThunk@ATL@@UEAAJXZ


	.global ?f820@_QIThunk@ATL@@UEAAJXZ
	.proc	?f820@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f820@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=820*8,r14	// r14 = &m_pUnk->vtbl[820] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[820]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[820].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[820].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f820@_QIThunk@ATL@@UEAAJXZ


	.global ?f821@_QIThunk@ATL@@UEAAJXZ
	.proc	?f821@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f821@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=821*8,r14	// r14 = &m_pUnk->vtbl[821] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[821]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[821].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[821].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f821@_QIThunk@ATL@@UEAAJXZ


	.global ?f822@_QIThunk@ATL@@UEAAJXZ
	.proc	?f822@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f822@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=822*8,r14	// r14 = &m_pUnk->vtbl[822] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[822]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[822].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[822].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f822@_QIThunk@ATL@@UEAAJXZ


	.global ?f823@_QIThunk@ATL@@UEAAJXZ
	.proc	?f823@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f823@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=823*8,r14	// r14 = &m_pUnk->vtbl[823] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[823]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[823].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[823].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f823@_QIThunk@ATL@@UEAAJXZ


	.global ?f824@_QIThunk@ATL@@UEAAJXZ
	.proc	?f824@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f824@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=824*8,r14	// r14 = &m_pUnk->vtbl[824] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[824]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[824].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[824].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f824@_QIThunk@ATL@@UEAAJXZ


	.global ?f825@_QIThunk@ATL@@UEAAJXZ
	.proc	?f825@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f825@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=825*8,r14	// r14 = &m_pUnk->vtbl[825] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[825]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[825].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[825].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f825@_QIThunk@ATL@@UEAAJXZ


	.global ?f826@_QIThunk@ATL@@UEAAJXZ
	.proc	?f826@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f826@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=826*8,r14	// r14 = &m_pUnk->vtbl[826] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[826]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[826].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[826].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f826@_QIThunk@ATL@@UEAAJXZ


	.global ?f827@_QIThunk@ATL@@UEAAJXZ
	.proc	?f827@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f827@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=827*8,r14	// r14 = &m_pUnk->vtbl[827] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[827]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[827].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[827].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f827@_QIThunk@ATL@@UEAAJXZ


	.global ?f828@_QIThunk@ATL@@UEAAJXZ
	.proc	?f828@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f828@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=828*8,r14	// r14 = &m_pUnk->vtbl[828] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[828]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[828].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[828].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f828@_QIThunk@ATL@@UEAAJXZ


	.global ?f829@_QIThunk@ATL@@UEAAJXZ
	.proc	?f829@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f829@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=829*8,r14	// r14 = &m_pUnk->vtbl[829] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[829]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[829].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[829].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f829@_QIThunk@ATL@@UEAAJXZ


	.global ?f830@_QIThunk@ATL@@UEAAJXZ
	.proc	?f830@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f830@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=830*8,r14	// r14 = &m_pUnk->vtbl[830] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[830]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[830].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[830].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f830@_QIThunk@ATL@@UEAAJXZ


	.global ?f831@_QIThunk@ATL@@UEAAJXZ
	.proc	?f831@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f831@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=831*8,r14	// r14 = &m_pUnk->vtbl[831] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[831]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[831].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[831].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f831@_QIThunk@ATL@@UEAAJXZ


	.global ?f832@_QIThunk@ATL@@UEAAJXZ
	.proc	?f832@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f832@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=832*8,r14	// r14 = &m_pUnk->vtbl[832] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[832]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[832].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[832].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f832@_QIThunk@ATL@@UEAAJXZ


	.global ?f833@_QIThunk@ATL@@UEAAJXZ
	.proc	?f833@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f833@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=833*8,r14	// r14 = &m_pUnk->vtbl[833] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[833]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[833].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[833].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f833@_QIThunk@ATL@@UEAAJXZ


	.global ?f834@_QIThunk@ATL@@UEAAJXZ
	.proc	?f834@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f834@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=834*8,r14	// r14 = &m_pUnk->vtbl[834] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[834]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[834].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[834].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f834@_QIThunk@ATL@@UEAAJXZ


	.global ?f835@_QIThunk@ATL@@UEAAJXZ
	.proc	?f835@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f835@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=835*8,r14	// r14 = &m_pUnk->vtbl[835] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[835]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[835].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[835].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f835@_QIThunk@ATL@@UEAAJXZ


	.global ?f836@_QIThunk@ATL@@UEAAJXZ
	.proc	?f836@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f836@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=836*8,r14	// r14 = &m_pUnk->vtbl[836] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[836]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[836].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[836].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f836@_QIThunk@ATL@@UEAAJXZ


	.global ?f837@_QIThunk@ATL@@UEAAJXZ
	.proc	?f837@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f837@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=837*8,r14	// r14 = &m_pUnk->vtbl[837] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[837]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[837].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[837].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f837@_QIThunk@ATL@@UEAAJXZ


	.global ?f838@_QIThunk@ATL@@UEAAJXZ
	.proc	?f838@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f838@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=838*8,r14	// r14 = &m_pUnk->vtbl[838] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[838]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[838].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[838].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f838@_QIThunk@ATL@@UEAAJXZ


	.global ?f839@_QIThunk@ATL@@UEAAJXZ
	.proc	?f839@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f839@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=839*8,r14	// r14 = &m_pUnk->vtbl[839] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[839]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[839].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[839].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f839@_QIThunk@ATL@@UEAAJXZ


	.global ?f840@_QIThunk@ATL@@UEAAJXZ
	.proc	?f840@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f840@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=840*8,r14	// r14 = &m_pUnk->vtbl[840] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[840]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[840].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[840].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f840@_QIThunk@ATL@@UEAAJXZ


	.global ?f841@_QIThunk@ATL@@UEAAJXZ
	.proc	?f841@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f841@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=841*8,r14	// r14 = &m_pUnk->vtbl[841] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[841]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[841].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[841].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f841@_QIThunk@ATL@@UEAAJXZ


	.global ?f842@_QIThunk@ATL@@UEAAJXZ
	.proc	?f842@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f842@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=842*8,r14	// r14 = &m_pUnk->vtbl[842] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[842]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[842].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[842].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f842@_QIThunk@ATL@@UEAAJXZ


	.global ?f843@_QIThunk@ATL@@UEAAJXZ
	.proc	?f843@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f843@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=843*8,r14	// r14 = &m_pUnk->vtbl[843] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[843]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[843].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[843].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f843@_QIThunk@ATL@@UEAAJXZ


	.global ?f844@_QIThunk@ATL@@UEAAJXZ
	.proc	?f844@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f844@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=844*8,r14	// r14 = &m_pUnk->vtbl[844] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[844]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[844].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[844].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f844@_QIThunk@ATL@@UEAAJXZ


	.global ?f845@_QIThunk@ATL@@UEAAJXZ
	.proc	?f845@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f845@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=845*8,r14	// r14 = &m_pUnk->vtbl[845] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[845]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[845].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[845].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f845@_QIThunk@ATL@@UEAAJXZ


	.global ?f846@_QIThunk@ATL@@UEAAJXZ
	.proc	?f846@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f846@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=846*8,r14	// r14 = &m_pUnk->vtbl[846] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[846]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[846].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[846].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f846@_QIThunk@ATL@@UEAAJXZ


	.global ?f847@_QIThunk@ATL@@UEAAJXZ
	.proc	?f847@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f847@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=847*8,r14	// r14 = &m_pUnk->vtbl[847] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[847]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[847].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[847].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f847@_QIThunk@ATL@@UEAAJXZ


	.global ?f848@_QIThunk@ATL@@UEAAJXZ
	.proc	?f848@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f848@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=848*8,r14	// r14 = &m_pUnk->vtbl[848] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[848]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[848].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[848].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f848@_QIThunk@ATL@@UEAAJXZ


	.global ?f849@_QIThunk@ATL@@UEAAJXZ
	.proc	?f849@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f849@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=849*8,r14	// r14 = &m_pUnk->vtbl[849] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[849]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[849].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[849].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f849@_QIThunk@ATL@@UEAAJXZ


	.global ?f850@_QIThunk@ATL@@UEAAJXZ
	.proc	?f850@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f850@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=850*8,r14	// r14 = &m_pUnk->vtbl[850] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[850]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[850].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[850].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f850@_QIThunk@ATL@@UEAAJXZ


	.global ?f851@_QIThunk@ATL@@UEAAJXZ
	.proc	?f851@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f851@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=851*8,r14	// r14 = &m_pUnk->vtbl[851] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[851]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[851].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[851].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f851@_QIThunk@ATL@@UEAAJXZ


	.global ?f852@_QIThunk@ATL@@UEAAJXZ
	.proc	?f852@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f852@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=852*8,r14	// r14 = &m_pUnk->vtbl[852] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[852]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[852].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[852].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f852@_QIThunk@ATL@@UEAAJXZ


	.global ?f853@_QIThunk@ATL@@UEAAJXZ
	.proc	?f853@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f853@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=853*8,r14	// r14 = &m_pUnk->vtbl[853] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[853]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[853].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[853].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f853@_QIThunk@ATL@@UEAAJXZ


	.global ?f854@_QIThunk@ATL@@UEAAJXZ
	.proc	?f854@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f854@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=854*8,r14	// r14 = &m_pUnk->vtbl[854] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[854]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[854].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[854].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f854@_QIThunk@ATL@@UEAAJXZ


	.global ?f855@_QIThunk@ATL@@UEAAJXZ
	.proc	?f855@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f855@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=855*8,r14	// r14 = &m_pUnk->vtbl[855] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[855]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[855].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[855].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f855@_QIThunk@ATL@@UEAAJXZ


	.global ?f856@_QIThunk@ATL@@UEAAJXZ
	.proc	?f856@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f856@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=856*8,r14	// r14 = &m_pUnk->vtbl[856] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[856]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[856].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[856].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f856@_QIThunk@ATL@@UEAAJXZ


	.global ?f857@_QIThunk@ATL@@UEAAJXZ
	.proc	?f857@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f857@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=857*8,r14	// r14 = &m_pUnk->vtbl[857] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[857]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[857].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[857].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f857@_QIThunk@ATL@@UEAAJXZ


	.global ?f858@_QIThunk@ATL@@UEAAJXZ
	.proc	?f858@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f858@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=858*8,r14	// r14 = &m_pUnk->vtbl[858] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[858]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[858].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[858].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f858@_QIThunk@ATL@@UEAAJXZ


	.global ?f859@_QIThunk@ATL@@UEAAJXZ
	.proc	?f859@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f859@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=859*8,r14	// r14 = &m_pUnk->vtbl[859] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[859]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[859].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[859].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f859@_QIThunk@ATL@@UEAAJXZ


	.global ?f860@_QIThunk@ATL@@UEAAJXZ
	.proc	?f860@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f860@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=860*8,r14	// r14 = &m_pUnk->vtbl[860] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[860]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[860].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[860].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f860@_QIThunk@ATL@@UEAAJXZ


	.global ?f861@_QIThunk@ATL@@UEAAJXZ
	.proc	?f861@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f861@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=861*8,r14	// r14 = &m_pUnk->vtbl[861] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[861]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[861].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[861].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f861@_QIThunk@ATL@@UEAAJXZ


	.global ?f862@_QIThunk@ATL@@UEAAJXZ
	.proc	?f862@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f862@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=862*8,r14	// r14 = &m_pUnk->vtbl[862] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[862]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[862].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[862].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f862@_QIThunk@ATL@@UEAAJXZ


	.global ?f863@_QIThunk@ATL@@UEAAJXZ
	.proc	?f863@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f863@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=863*8,r14	// r14 = &m_pUnk->vtbl[863] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[863]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[863].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[863].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f863@_QIThunk@ATL@@UEAAJXZ


	.global ?f864@_QIThunk@ATL@@UEAAJXZ
	.proc	?f864@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f864@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=864*8,r14	// r14 = &m_pUnk->vtbl[864] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[864]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[864].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[864].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f864@_QIThunk@ATL@@UEAAJXZ


	.global ?f865@_QIThunk@ATL@@UEAAJXZ
	.proc	?f865@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f865@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=865*8,r14	// r14 = &m_pUnk->vtbl[865] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[865]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[865].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[865].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f865@_QIThunk@ATL@@UEAAJXZ


	.global ?f866@_QIThunk@ATL@@UEAAJXZ
	.proc	?f866@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f866@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=866*8,r14	// r14 = &m_pUnk->vtbl[866] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[866]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[866].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[866].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f866@_QIThunk@ATL@@UEAAJXZ


	.global ?f867@_QIThunk@ATL@@UEAAJXZ
	.proc	?f867@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f867@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=867*8,r14	// r14 = &m_pUnk->vtbl[867] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[867]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[867].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[867].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f867@_QIThunk@ATL@@UEAAJXZ


	.global ?f868@_QIThunk@ATL@@UEAAJXZ
	.proc	?f868@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f868@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=868*8,r14	// r14 = &m_pUnk->vtbl[868] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[868]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[868].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[868].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f868@_QIThunk@ATL@@UEAAJXZ


	.global ?f869@_QIThunk@ATL@@UEAAJXZ
	.proc	?f869@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f869@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=869*8,r14	// r14 = &m_pUnk->vtbl[869] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[869]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[869].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[869].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f869@_QIThunk@ATL@@UEAAJXZ


	.global ?f870@_QIThunk@ATL@@UEAAJXZ
	.proc	?f870@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f870@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=870*8,r14	// r14 = &m_pUnk->vtbl[870] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[870]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[870].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[870].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f870@_QIThunk@ATL@@UEAAJXZ


	.global ?f871@_QIThunk@ATL@@UEAAJXZ
	.proc	?f871@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f871@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=871*8,r14	// r14 = &m_pUnk->vtbl[871] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[871]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[871].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[871].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f871@_QIThunk@ATL@@UEAAJXZ


	.global ?f872@_QIThunk@ATL@@UEAAJXZ
	.proc	?f872@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f872@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=872*8,r14	// r14 = &m_pUnk->vtbl[872] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[872]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[872].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[872].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f872@_QIThunk@ATL@@UEAAJXZ


	.global ?f873@_QIThunk@ATL@@UEAAJXZ
	.proc	?f873@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f873@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=873*8,r14	// r14 = &m_pUnk->vtbl[873] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[873]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[873].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[873].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f873@_QIThunk@ATL@@UEAAJXZ


	.global ?f874@_QIThunk@ATL@@UEAAJXZ
	.proc	?f874@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f874@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=874*8,r14	// r14 = &m_pUnk->vtbl[874] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[874]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[874].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[874].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f874@_QIThunk@ATL@@UEAAJXZ


	.global ?f875@_QIThunk@ATL@@UEAAJXZ
	.proc	?f875@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f875@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=875*8,r14	// r14 = &m_pUnk->vtbl[875] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[875]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[875].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[875].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f875@_QIThunk@ATL@@UEAAJXZ


	.global ?f876@_QIThunk@ATL@@UEAAJXZ
	.proc	?f876@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f876@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=876*8,r14	// r14 = &m_pUnk->vtbl[876] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[876]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[876].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[876].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f876@_QIThunk@ATL@@UEAAJXZ


	.global ?f877@_QIThunk@ATL@@UEAAJXZ
	.proc	?f877@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f877@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=877*8,r14	// r14 = &m_pUnk->vtbl[877] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[877]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[877].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[877].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f877@_QIThunk@ATL@@UEAAJXZ


	.global ?f878@_QIThunk@ATL@@UEAAJXZ
	.proc	?f878@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f878@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=878*8,r14	// r14 = &m_pUnk->vtbl[878] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[878]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[878].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[878].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f878@_QIThunk@ATL@@UEAAJXZ


	.global ?f879@_QIThunk@ATL@@UEAAJXZ
	.proc	?f879@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f879@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=879*8,r14	// r14 = &m_pUnk->vtbl[879] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[879]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[879].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[879].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f879@_QIThunk@ATL@@UEAAJXZ


	.global ?f880@_QIThunk@ATL@@UEAAJXZ
	.proc	?f880@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f880@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=880*8,r14	// r14 = &m_pUnk->vtbl[880] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[880]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[880].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[880].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f880@_QIThunk@ATL@@UEAAJXZ


	.global ?f881@_QIThunk@ATL@@UEAAJXZ
	.proc	?f881@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f881@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=881*8,r14	// r14 = &m_pUnk->vtbl[881] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[881]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[881].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[881].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f881@_QIThunk@ATL@@UEAAJXZ


	.global ?f882@_QIThunk@ATL@@UEAAJXZ
	.proc	?f882@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f882@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=882*8,r14	// r14 = &m_pUnk->vtbl[882] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[882]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[882].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[882].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f882@_QIThunk@ATL@@UEAAJXZ


	.global ?f883@_QIThunk@ATL@@UEAAJXZ
	.proc	?f883@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f883@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=883*8,r14	// r14 = &m_pUnk->vtbl[883] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[883]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[883].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[883].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f883@_QIThunk@ATL@@UEAAJXZ


	.global ?f884@_QIThunk@ATL@@UEAAJXZ
	.proc	?f884@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f884@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=884*8,r14	// r14 = &m_pUnk->vtbl[884] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[884]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[884].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[884].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f884@_QIThunk@ATL@@UEAAJXZ


	.global ?f885@_QIThunk@ATL@@UEAAJXZ
	.proc	?f885@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f885@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=885*8,r14	// r14 = &m_pUnk->vtbl[885] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[885]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[885].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[885].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f885@_QIThunk@ATL@@UEAAJXZ


	.global ?f886@_QIThunk@ATL@@UEAAJXZ
	.proc	?f886@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f886@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=886*8,r14	// r14 = &m_pUnk->vtbl[886] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[886]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[886].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[886].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f886@_QIThunk@ATL@@UEAAJXZ


	.global ?f887@_QIThunk@ATL@@UEAAJXZ
	.proc	?f887@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f887@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=887*8,r14	// r14 = &m_pUnk->vtbl[887] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[887]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[887].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[887].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f887@_QIThunk@ATL@@UEAAJXZ


	.global ?f888@_QIThunk@ATL@@UEAAJXZ
	.proc	?f888@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f888@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=888*8,r14	// r14 = &m_pUnk->vtbl[888] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[888]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[888].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[888].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f888@_QIThunk@ATL@@UEAAJXZ


	.global ?f889@_QIThunk@ATL@@UEAAJXZ
	.proc	?f889@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f889@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=889*8,r14	// r14 = &m_pUnk->vtbl[889] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[889]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[889].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[889].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f889@_QIThunk@ATL@@UEAAJXZ


	.global ?f890@_QIThunk@ATL@@UEAAJXZ
	.proc	?f890@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f890@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=890*8,r14	// r14 = &m_pUnk->vtbl[890] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[890]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[890].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[890].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f890@_QIThunk@ATL@@UEAAJXZ


	.global ?f891@_QIThunk@ATL@@UEAAJXZ
	.proc	?f891@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f891@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=891*8,r14	// r14 = &m_pUnk->vtbl[891] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[891]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[891].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[891].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f891@_QIThunk@ATL@@UEAAJXZ


	.global ?f892@_QIThunk@ATL@@UEAAJXZ
	.proc	?f892@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f892@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=892*8,r14	// r14 = &m_pUnk->vtbl[892] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[892]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[892].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[892].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f892@_QIThunk@ATL@@UEAAJXZ


	.global ?f893@_QIThunk@ATL@@UEAAJXZ
	.proc	?f893@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f893@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=893*8,r14	// r14 = &m_pUnk->vtbl[893] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[893]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[893].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[893].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f893@_QIThunk@ATL@@UEAAJXZ


	.global ?f894@_QIThunk@ATL@@UEAAJXZ
	.proc	?f894@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f894@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=894*8,r14	// r14 = &m_pUnk->vtbl[894] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[894]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[894].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[894].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f894@_QIThunk@ATL@@UEAAJXZ


	.global ?f895@_QIThunk@ATL@@UEAAJXZ
	.proc	?f895@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f895@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=895*8,r14	// r14 = &m_pUnk->vtbl[895] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[895]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[895].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[895].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f895@_QIThunk@ATL@@UEAAJXZ


	.global ?f896@_QIThunk@ATL@@UEAAJXZ
	.proc	?f896@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f896@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=896*8,r14	// r14 = &m_pUnk->vtbl[896] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[896]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[896].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[896].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f896@_QIThunk@ATL@@UEAAJXZ


	.global ?f897@_QIThunk@ATL@@UEAAJXZ
	.proc	?f897@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f897@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=897*8,r14	// r14 = &m_pUnk->vtbl[897] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[897]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[897].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[897].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f897@_QIThunk@ATL@@UEAAJXZ


	.global ?f898@_QIThunk@ATL@@UEAAJXZ
	.proc	?f898@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f898@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=898*8,r14	// r14 = &m_pUnk->vtbl[898] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[898]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[898].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[898].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f898@_QIThunk@ATL@@UEAAJXZ


	.global ?f899@_QIThunk@ATL@@UEAAJXZ
	.proc	?f899@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f899@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=899*8,r14	// r14 = &m_pUnk->vtbl[899] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[899]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[899].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[899].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f899@_QIThunk@ATL@@UEAAJXZ


	.global ?f900@_QIThunk@ATL@@UEAAJXZ
	.proc	?f900@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f900@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=900*8,r14	// r14 = &m_pUnk->vtbl[900] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[900]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[900].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[900].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f900@_QIThunk@ATL@@UEAAJXZ


	.global ?f901@_QIThunk@ATL@@UEAAJXZ
	.proc	?f901@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f901@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=901*8,r14	// r14 = &m_pUnk->vtbl[901] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[901]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[901].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[901].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f901@_QIThunk@ATL@@UEAAJXZ


	.global ?f902@_QIThunk@ATL@@UEAAJXZ
	.proc	?f902@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f902@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=902*8,r14	// r14 = &m_pUnk->vtbl[902] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[902]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[902].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[902].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f902@_QIThunk@ATL@@UEAAJXZ


	.global ?f903@_QIThunk@ATL@@UEAAJXZ
	.proc	?f903@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f903@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=903*8,r14	// r14 = &m_pUnk->vtbl[903] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[903]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[903].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[903].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f903@_QIThunk@ATL@@UEAAJXZ


	.global ?f904@_QIThunk@ATL@@UEAAJXZ
	.proc	?f904@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f904@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=904*8,r14	// r14 = &m_pUnk->vtbl[904] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[904]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[904].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[904].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f904@_QIThunk@ATL@@UEAAJXZ


	.global ?f905@_QIThunk@ATL@@UEAAJXZ
	.proc	?f905@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f905@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=905*8,r14	// r14 = &m_pUnk->vtbl[905] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[905]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[905].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[905].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f905@_QIThunk@ATL@@UEAAJXZ


	.global ?f906@_QIThunk@ATL@@UEAAJXZ
	.proc	?f906@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f906@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=906*8,r14	// r14 = &m_pUnk->vtbl[906] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[906]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[906].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[906].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f906@_QIThunk@ATL@@UEAAJXZ


	.global ?f907@_QIThunk@ATL@@UEAAJXZ
	.proc	?f907@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f907@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=907*8,r14	// r14 = &m_pUnk->vtbl[907] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[907]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[907].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[907].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f907@_QIThunk@ATL@@UEAAJXZ


	.global ?f908@_QIThunk@ATL@@UEAAJXZ
	.proc	?f908@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f908@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=908*8,r14	// r14 = &m_pUnk->vtbl[908] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[908]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[908].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[908].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f908@_QIThunk@ATL@@UEAAJXZ


	.global ?f909@_QIThunk@ATL@@UEAAJXZ
	.proc	?f909@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f909@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=909*8,r14	// r14 = &m_pUnk->vtbl[909] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[909]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[909].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[909].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f909@_QIThunk@ATL@@UEAAJXZ


	.global ?f910@_QIThunk@ATL@@UEAAJXZ
	.proc	?f910@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f910@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=910*8,r14	// r14 = &m_pUnk->vtbl[910] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[910]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[910].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[910].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f910@_QIThunk@ATL@@UEAAJXZ


	.global ?f911@_QIThunk@ATL@@UEAAJXZ
	.proc	?f911@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f911@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=911*8,r14	// r14 = &m_pUnk->vtbl[911] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[911]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[911].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[911].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f911@_QIThunk@ATL@@UEAAJXZ


	.global ?f912@_QIThunk@ATL@@UEAAJXZ
	.proc	?f912@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f912@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=912*8,r14	// r14 = &m_pUnk->vtbl[912] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[912]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[912].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[912].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f912@_QIThunk@ATL@@UEAAJXZ


	.global ?f913@_QIThunk@ATL@@UEAAJXZ
	.proc	?f913@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f913@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=913*8,r14	// r14 = &m_pUnk->vtbl[913] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[913]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[913].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[913].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f913@_QIThunk@ATL@@UEAAJXZ


	.global ?f914@_QIThunk@ATL@@UEAAJXZ
	.proc	?f914@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f914@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=914*8,r14	// r14 = &m_pUnk->vtbl[914] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[914]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[914].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[914].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f914@_QIThunk@ATL@@UEAAJXZ


	.global ?f915@_QIThunk@ATL@@UEAAJXZ
	.proc	?f915@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f915@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=915*8,r14	// r14 = &m_pUnk->vtbl[915] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[915]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[915].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[915].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f915@_QIThunk@ATL@@UEAAJXZ


	.global ?f916@_QIThunk@ATL@@UEAAJXZ
	.proc	?f916@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f916@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=916*8,r14	// r14 = &m_pUnk->vtbl[916] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[916]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[916].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[916].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f916@_QIThunk@ATL@@UEAAJXZ


	.global ?f917@_QIThunk@ATL@@UEAAJXZ
	.proc	?f917@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f917@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=917*8,r14	// r14 = &m_pUnk->vtbl[917] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[917]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[917].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[917].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f917@_QIThunk@ATL@@UEAAJXZ


	.global ?f918@_QIThunk@ATL@@UEAAJXZ
	.proc	?f918@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f918@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=918*8,r14	// r14 = &m_pUnk->vtbl[918] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[918]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[918].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[918].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f918@_QIThunk@ATL@@UEAAJXZ


	.global ?f919@_QIThunk@ATL@@UEAAJXZ
	.proc	?f919@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f919@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=919*8,r14	// r14 = &m_pUnk->vtbl[919] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[919]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[919].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[919].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f919@_QIThunk@ATL@@UEAAJXZ


	.global ?f920@_QIThunk@ATL@@UEAAJXZ
	.proc	?f920@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f920@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=920*8,r14	// r14 = &m_pUnk->vtbl[920] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[920]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[920].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[920].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f920@_QIThunk@ATL@@UEAAJXZ


	.global ?f921@_QIThunk@ATL@@UEAAJXZ
	.proc	?f921@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f921@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=921*8,r14	// r14 = &m_pUnk->vtbl[921] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[921]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[921].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[921].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f921@_QIThunk@ATL@@UEAAJXZ


	.global ?f922@_QIThunk@ATL@@UEAAJXZ
	.proc	?f922@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f922@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=922*8,r14	// r14 = &m_pUnk->vtbl[922] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[922]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[922].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[922].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f922@_QIThunk@ATL@@UEAAJXZ


	.global ?f923@_QIThunk@ATL@@UEAAJXZ
	.proc	?f923@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f923@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=923*8,r14	// r14 = &m_pUnk->vtbl[923] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[923]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[923].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[923].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f923@_QIThunk@ATL@@UEAAJXZ


	.global ?f924@_QIThunk@ATL@@UEAAJXZ
	.proc	?f924@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f924@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=924*8,r14	// r14 = &m_pUnk->vtbl[924] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[924]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[924].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[924].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f924@_QIThunk@ATL@@UEAAJXZ


	.global ?f925@_QIThunk@ATL@@UEAAJXZ
	.proc	?f925@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f925@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=925*8,r14	// r14 = &m_pUnk->vtbl[925] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[925]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[925].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[925].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f925@_QIThunk@ATL@@UEAAJXZ


	.global ?f926@_QIThunk@ATL@@UEAAJXZ
	.proc	?f926@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f926@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=926*8,r14	// r14 = &m_pUnk->vtbl[926] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[926]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[926].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[926].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f926@_QIThunk@ATL@@UEAAJXZ


	.global ?f927@_QIThunk@ATL@@UEAAJXZ
	.proc	?f927@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f927@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=927*8,r14	// r14 = &m_pUnk->vtbl[927] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[927]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[927].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[927].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f927@_QIThunk@ATL@@UEAAJXZ


	.global ?f928@_QIThunk@ATL@@UEAAJXZ
	.proc	?f928@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f928@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=928*8,r14	// r14 = &m_pUnk->vtbl[928] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[928]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[928].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[928].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f928@_QIThunk@ATL@@UEAAJXZ


	.global ?f929@_QIThunk@ATL@@UEAAJXZ
	.proc	?f929@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f929@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=929*8,r14	// r14 = &m_pUnk->vtbl[929] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[929]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[929].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[929].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f929@_QIThunk@ATL@@UEAAJXZ


	.global ?f930@_QIThunk@ATL@@UEAAJXZ
	.proc	?f930@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f930@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=930*8,r14	// r14 = &m_pUnk->vtbl[930] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[930]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[930].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[930].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f930@_QIThunk@ATL@@UEAAJXZ


	.global ?f931@_QIThunk@ATL@@UEAAJXZ
	.proc	?f931@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f931@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=931*8,r14	// r14 = &m_pUnk->vtbl[931] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[931]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[931].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[931].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f931@_QIThunk@ATL@@UEAAJXZ


	.global ?f932@_QIThunk@ATL@@UEAAJXZ
	.proc	?f932@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f932@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=932*8,r14	// r14 = &m_pUnk->vtbl[932] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[932]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[932].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[932].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f932@_QIThunk@ATL@@UEAAJXZ


	.global ?f933@_QIThunk@ATL@@UEAAJXZ
	.proc	?f933@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f933@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=933*8,r14	// r14 = &m_pUnk->vtbl[933] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[933]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[933].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[933].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f933@_QIThunk@ATL@@UEAAJXZ


	.global ?f934@_QIThunk@ATL@@UEAAJXZ
	.proc	?f934@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f934@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=934*8,r14	// r14 = &m_pUnk->vtbl[934] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[934]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[934].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[934].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f934@_QIThunk@ATL@@UEAAJXZ


	.global ?f935@_QIThunk@ATL@@UEAAJXZ
	.proc	?f935@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f935@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=935*8,r14	// r14 = &m_pUnk->vtbl[935] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[935]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[935].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[935].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f935@_QIThunk@ATL@@UEAAJXZ


	.global ?f936@_QIThunk@ATL@@UEAAJXZ
	.proc	?f936@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f936@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=936*8,r14	// r14 = &m_pUnk->vtbl[936] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[936]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[936].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[936].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f936@_QIThunk@ATL@@UEAAJXZ


	.global ?f937@_QIThunk@ATL@@UEAAJXZ
	.proc	?f937@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f937@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=937*8,r14	// r14 = &m_pUnk->vtbl[937] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[937]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[937].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[937].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f937@_QIThunk@ATL@@UEAAJXZ


	.global ?f938@_QIThunk@ATL@@UEAAJXZ
	.proc	?f938@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f938@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=938*8,r14	// r14 = &m_pUnk->vtbl[938] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[938]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[938].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[938].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f938@_QIThunk@ATL@@UEAAJXZ


	.global ?f939@_QIThunk@ATL@@UEAAJXZ
	.proc	?f939@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f939@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=939*8,r14	// r14 = &m_pUnk->vtbl[939] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[939]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[939].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[939].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f939@_QIThunk@ATL@@UEAAJXZ


	.global ?f940@_QIThunk@ATL@@UEAAJXZ
	.proc	?f940@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f940@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=940*8,r14	// r14 = &m_pUnk->vtbl[940] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[940]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[940].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[940].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f940@_QIThunk@ATL@@UEAAJXZ


	.global ?f941@_QIThunk@ATL@@UEAAJXZ
	.proc	?f941@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f941@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=941*8,r14	// r14 = &m_pUnk->vtbl[941] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[941]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[941].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[941].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f941@_QIThunk@ATL@@UEAAJXZ


	.global ?f942@_QIThunk@ATL@@UEAAJXZ
	.proc	?f942@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f942@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=942*8,r14	// r14 = &m_pUnk->vtbl[942] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[942]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[942].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[942].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f942@_QIThunk@ATL@@UEAAJXZ


	.global ?f943@_QIThunk@ATL@@UEAAJXZ
	.proc	?f943@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f943@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=943*8,r14	// r14 = &m_pUnk->vtbl[943] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[943]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[943].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[943].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f943@_QIThunk@ATL@@UEAAJXZ


	.global ?f944@_QIThunk@ATL@@UEAAJXZ
	.proc	?f944@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f944@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=944*8,r14	// r14 = &m_pUnk->vtbl[944] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[944]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[944].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[944].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f944@_QIThunk@ATL@@UEAAJXZ


	.global ?f945@_QIThunk@ATL@@UEAAJXZ
	.proc	?f945@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f945@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=945*8,r14	// r14 = &m_pUnk->vtbl[945] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[945]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[945].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[945].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f945@_QIThunk@ATL@@UEAAJXZ


	.global ?f946@_QIThunk@ATL@@UEAAJXZ
	.proc	?f946@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f946@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=946*8,r14	// r14 = &m_pUnk->vtbl[946] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[946]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[946].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[946].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f946@_QIThunk@ATL@@UEAAJXZ


	.global ?f947@_QIThunk@ATL@@UEAAJXZ
	.proc	?f947@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f947@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=947*8,r14	// r14 = &m_pUnk->vtbl[947] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[947]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[947].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[947].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f947@_QIThunk@ATL@@UEAAJXZ


	.global ?f948@_QIThunk@ATL@@UEAAJXZ
	.proc	?f948@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f948@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=948*8,r14	// r14 = &m_pUnk->vtbl[948] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[948]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[948].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[948].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f948@_QIThunk@ATL@@UEAAJXZ


	.global ?f949@_QIThunk@ATL@@UEAAJXZ
	.proc	?f949@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f949@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=949*8,r14	// r14 = &m_pUnk->vtbl[949] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[949]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[949].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[949].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f949@_QIThunk@ATL@@UEAAJXZ


	.global ?f950@_QIThunk@ATL@@UEAAJXZ
	.proc	?f950@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f950@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=950*8,r14	// r14 = &m_pUnk->vtbl[950] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[950]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[950].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[950].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f950@_QIThunk@ATL@@UEAAJXZ


	.global ?f951@_QIThunk@ATL@@UEAAJXZ
	.proc	?f951@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f951@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=951*8,r14	// r14 = &m_pUnk->vtbl[951] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[951]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[951].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[951].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f951@_QIThunk@ATL@@UEAAJXZ


	.global ?f952@_QIThunk@ATL@@UEAAJXZ
	.proc	?f952@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f952@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=952*8,r14	// r14 = &m_pUnk->vtbl[952] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[952]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[952].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[952].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f952@_QIThunk@ATL@@UEAAJXZ


	.global ?f953@_QIThunk@ATL@@UEAAJXZ
	.proc	?f953@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f953@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=953*8,r14	// r14 = &m_pUnk->vtbl[953] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[953]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[953].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[953].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f953@_QIThunk@ATL@@UEAAJXZ


	.global ?f954@_QIThunk@ATL@@UEAAJXZ
	.proc	?f954@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f954@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=954*8,r14	// r14 = &m_pUnk->vtbl[954] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[954]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[954].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[954].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f954@_QIThunk@ATL@@UEAAJXZ


	.global ?f955@_QIThunk@ATL@@UEAAJXZ
	.proc	?f955@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f955@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=955*8,r14	// r14 = &m_pUnk->vtbl[955] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[955]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[955].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[955].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f955@_QIThunk@ATL@@UEAAJXZ


	.global ?f956@_QIThunk@ATL@@UEAAJXZ
	.proc	?f956@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f956@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=956*8,r14	// r14 = &m_pUnk->vtbl[956] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[956]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[956].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[956].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f956@_QIThunk@ATL@@UEAAJXZ


	.global ?f957@_QIThunk@ATL@@UEAAJXZ
	.proc	?f957@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f957@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=957*8,r14	// r14 = &m_pUnk->vtbl[957] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[957]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[957].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[957].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f957@_QIThunk@ATL@@UEAAJXZ


	.global ?f958@_QIThunk@ATL@@UEAAJXZ
	.proc	?f958@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f958@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=958*8,r14	// r14 = &m_pUnk->vtbl[958] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[958]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[958].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[958].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f958@_QIThunk@ATL@@UEAAJXZ


	.global ?f959@_QIThunk@ATL@@UEAAJXZ
	.proc	?f959@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f959@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=959*8,r14	// r14 = &m_pUnk->vtbl[959] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[959]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[959].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[959].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f959@_QIThunk@ATL@@UEAAJXZ


	.global ?f960@_QIThunk@ATL@@UEAAJXZ
	.proc	?f960@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f960@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=960*8,r14	// r14 = &m_pUnk->vtbl[960] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[960]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[960].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[960].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f960@_QIThunk@ATL@@UEAAJXZ


	.global ?f961@_QIThunk@ATL@@UEAAJXZ
	.proc	?f961@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f961@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=961*8,r14	// r14 = &m_pUnk->vtbl[961] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[961]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[961].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[961].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f961@_QIThunk@ATL@@UEAAJXZ


	.global ?f962@_QIThunk@ATL@@UEAAJXZ
	.proc	?f962@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f962@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=962*8,r14	// r14 = &m_pUnk->vtbl[962] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[962]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[962].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[962].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f962@_QIThunk@ATL@@UEAAJXZ


	.global ?f963@_QIThunk@ATL@@UEAAJXZ
	.proc	?f963@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f963@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=963*8,r14	// r14 = &m_pUnk->vtbl[963] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[963]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[963].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[963].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f963@_QIThunk@ATL@@UEAAJXZ


	.global ?f964@_QIThunk@ATL@@UEAAJXZ
	.proc	?f964@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f964@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=964*8,r14	// r14 = &m_pUnk->vtbl[964] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[964]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[964].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[964].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f964@_QIThunk@ATL@@UEAAJXZ


	.global ?f965@_QIThunk@ATL@@UEAAJXZ
	.proc	?f965@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f965@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=965*8,r14	// r14 = &m_pUnk->vtbl[965] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[965]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[965].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[965].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f965@_QIThunk@ATL@@UEAAJXZ


	.global ?f966@_QIThunk@ATL@@UEAAJXZ
	.proc	?f966@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f966@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=966*8,r14	// r14 = &m_pUnk->vtbl[966] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[966]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[966].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[966].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f966@_QIThunk@ATL@@UEAAJXZ


	.global ?f967@_QIThunk@ATL@@UEAAJXZ
	.proc	?f967@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f967@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=967*8,r14	// r14 = &m_pUnk->vtbl[967] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[967]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[967].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[967].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f967@_QIThunk@ATL@@UEAAJXZ


	.global ?f968@_QIThunk@ATL@@UEAAJXZ
	.proc	?f968@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f968@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=968*8,r14	// r14 = &m_pUnk->vtbl[968] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[968]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[968].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[968].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f968@_QIThunk@ATL@@UEAAJXZ


	.global ?f969@_QIThunk@ATL@@UEAAJXZ
	.proc	?f969@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f969@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=969*8,r14	// r14 = &m_pUnk->vtbl[969] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[969]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[969].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[969].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f969@_QIThunk@ATL@@UEAAJXZ


	.global ?f970@_QIThunk@ATL@@UEAAJXZ
	.proc	?f970@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f970@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=970*8,r14	// r14 = &m_pUnk->vtbl[970] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[970]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[970].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[970].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f970@_QIThunk@ATL@@UEAAJXZ


	.global ?f971@_QIThunk@ATL@@UEAAJXZ
	.proc	?f971@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f971@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=971*8,r14	// r14 = &m_pUnk->vtbl[971] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[971]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[971].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[971].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f971@_QIThunk@ATL@@UEAAJXZ


	.global ?f972@_QIThunk@ATL@@UEAAJXZ
	.proc	?f972@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f972@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=972*8,r14	// r14 = &m_pUnk->vtbl[972] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[972]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[972].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[972].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f972@_QIThunk@ATL@@UEAAJXZ


	.global ?f973@_QIThunk@ATL@@UEAAJXZ
	.proc	?f973@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f973@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=973*8,r14	// r14 = &m_pUnk->vtbl[973] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[973]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[973].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[973].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f973@_QIThunk@ATL@@UEAAJXZ


	.global ?f974@_QIThunk@ATL@@UEAAJXZ
	.proc	?f974@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f974@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=974*8,r14	// r14 = &m_pUnk->vtbl[974] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[974]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[974].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[974].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f974@_QIThunk@ATL@@UEAAJXZ


	.global ?f975@_QIThunk@ATL@@UEAAJXZ
	.proc	?f975@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f975@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=975*8,r14	// r14 = &m_pUnk->vtbl[975] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[975]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[975].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[975].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f975@_QIThunk@ATL@@UEAAJXZ


	.global ?f976@_QIThunk@ATL@@UEAAJXZ
	.proc	?f976@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f976@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=976*8,r14	// r14 = &m_pUnk->vtbl[976] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[976]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[976].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[976].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f976@_QIThunk@ATL@@UEAAJXZ


	.global ?f977@_QIThunk@ATL@@UEAAJXZ
	.proc	?f977@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f977@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=977*8,r14	// r14 = &m_pUnk->vtbl[977] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[977]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[977].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[977].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f977@_QIThunk@ATL@@UEAAJXZ


	.global ?f978@_QIThunk@ATL@@UEAAJXZ
	.proc	?f978@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f978@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=978*8,r14	// r14 = &m_pUnk->vtbl[978] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[978]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[978].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[978].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f978@_QIThunk@ATL@@UEAAJXZ


	.global ?f979@_QIThunk@ATL@@UEAAJXZ
	.proc	?f979@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f979@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=979*8,r14	// r14 = &m_pUnk->vtbl[979] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[979]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[979].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[979].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f979@_QIThunk@ATL@@UEAAJXZ


	.global ?f980@_QIThunk@ATL@@UEAAJXZ
	.proc	?f980@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f980@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=980*8,r14	// r14 = &m_pUnk->vtbl[980] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[980]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[980].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[980].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f980@_QIThunk@ATL@@UEAAJXZ


	.global ?f981@_QIThunk@ATL@@UEAAJXZ
	.proc	?f981@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f981@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=981*8,r14	// r14 = &m_pUnk->vtbl[981] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[981]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[981].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[981].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f981@_QIThunk@ATL@@UEAAJXZ


	.global ?f982@_QIThunk@ATL@@UEAAJXZ
	.proc	?f982@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f982@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=982*8,r14	// r14 = &m_pUnk->vtbl[982] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[982]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[982].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[982].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f982@_QIThunk@ATL@@UEAAJXZ


	.global ?f983@_QIThunk@ATL@@UEAAJXZ
	.proc	?f983@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f983@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=983*8,r14	// r14 = &m_pUnk->vtbl[983] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[983]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[983].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[983].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f983@_QIThunk@ATL@@UEAAJXZ


	.global ?f984@_QIThunk@ATL@@UEAAJXZ
	.proc	?f984@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f984@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=984*8,r14	// r14 = &m_pUnk->vtbl[984] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[984]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[984].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[984].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f984@_QIThunk@ATL@@UEAAJXZ


	.global ?f985@_QIThunk@ATL@@UEAAJXZ
	.proc	?f985@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f985@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=985*8,r14	// r14 = &m_pUnk->vtbl[985] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[985]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[985].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[985].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f985@_QIThunk@ATL@@UEAAJXZ


	.global ?f986@_QIThunk@ATL@@UEAAJXZ
	.proc	?f986@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f986@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=986*8,r14	// r14 = &m_pUnk->vtbl[986] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[986]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[986].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[986].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f986@_QIThunk@ATL@@UEAAJXZ


	.global ?f987@_QIThunk@ATL@@UEAAJXZ
	.proc	?f987@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f987@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=987*8,r14	// r14 = &m_pUnk->vtbl[987] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[987]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[987].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[987].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f987@_QIThunk@ATL@@UEAAJXZ


	.global ?f988@_QIThunk@ATL@@UEAAJXZ
	.proc	?f988@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f988@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=988*8,r14	// r14 = &m_pUnk->vtbl[988] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[988]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[988].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[988].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f988@_QIThunk@ATL@@UEAAJXZ


	.global ?f989@_QIThunk@ATL@@UEAAJXZ
	.proc	?f989@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f989@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=989*8,r14	// r14 = &m_pUnk->vtbl[989] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[989]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[989].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[989].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f989@_QIThunk@ATL@@UEAAJXZ


	.global ?f990@_QIThunk@ATL@@UEAAJXZ
	.proc	?f990@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f990@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=990*8,r14	// r14 = &m_pUnk->vtbl[990] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[990]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[990].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[990].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f990@_QIThunk@ATL@@UEAAJXZ


	.global ?f991@_QIThunk@ATL@@UEAAJXZ
	.proc	?f991@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f991@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=991*8,r14	// r14 = &m_pUnk->vtbl[991] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[991]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[991].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[991].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f991@_QIThunk@ATL@@UEAAJXZ


	.global ?f992@_QIThunk@ATL@@UEAAJXZ
	.proc	?f992@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f992@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=992*8,r14	// r14 = &m_pUnk->vtbl[992] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[992]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[992].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[992].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f992@_QIThunk@ATL@@UEAAJXZ


	.global ?f993@_QIThunk@ATL@@UEAAJXZ
	.proc	?f993@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f993@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=993*8,r14	// r14 = &m_pUnk->vtbl[993] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[993]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[993].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[993].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f993@_QIThunk@ATL@@UEAAJXZ


	.global ?f994@_QIThunk@ATL@@UEAAJXZ
	.proc	?f994@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f994@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=994*8,r14	// r14 = &m_pUnk->vtbl[994] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[994]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[994].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[994].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f994@_QIThunk@ATL@@UEAAJXZ


	.global ?f995@_QIThunk@ATL@@UEAAJXZ
	.proc	?f995@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f995@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=995*8,r14	// r14 = &m_pUnk->vtbl[995] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[995]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[995].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[995].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f995@_QIThunk@ATL@@UEAAJXZ


	.global ?f996@_QIThunk@ATL@@UEAAJXZ
	.proc	?f996@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f996@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=996*8,r14	// r14 = &m_pUnk->vtbl[996] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[996]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[996].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[996].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f996@_QIThunk@ATL@@UEAAJXZ


	.global ?f997@_QIThunk@ATL@@UEAAJXZ
	.proc	?f997@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f997@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=997*8,r14	// r14 = &m_pUnk->vtbl[997] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[997]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[997].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[997].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f997@_QIThunk@ATL@@UEAAJXZ


	.global ?f998@_QIThunk@ATL@@UEAAJXZ
	.proc	?f998@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f998@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=998*8,r14	// r14 = &m_pUnk->vtbl[998] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[998]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[998].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[998].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f998@_QIThunk@ATL@@UEAAJXZ


	.global ?f999@_QIThunk@ATL@@UEAAJXZ
	.proc	?f999@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f999@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=999*8,r14	// r14 = &m_pUnk->vtbl[999] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[999]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[999].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[999].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f999@_QIThunk@ATL@@UEAAJXZ


	.global ?f1000@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1000@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1000@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1000*8,r14	// r14 = &m_pUnk->vtbl[1000] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1000]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1000].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1000].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1000@_QIThunk@ATL@@UEAAJXZ


	.global ?f1001@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1001@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1001@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1001*8,r14	// r14 = &m_pUnk->vtbl[1001] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1001]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1001].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1001].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1001@_QIThunk@ATL@@UEAAJXZ


	.global ?f1002@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1002@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1002@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1002*8,r14	// r14 = &m_pUnk->vtbl[1002] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1002]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1002].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1002].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1002@_QIThunk@ATL@@UEAAJXZ


	.global ?f1003@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1003@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1003@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1003*8,r14	// r14 = &m_pUnk->vtbl[1003] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1003]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1003].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1003].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1003@_QIThunk@ATL@@UEAAJXZ


	.global ?f1004@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1004@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1004@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1004*8,r14	// r14 = &m_pUnk->vtbl[1004] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1004]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1004].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1004].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1004@_QIThunk@ATL@@UEAAJXZ


	.global ?f1005@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1005@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1005@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1005*8,r14	// r14 = &m_pUnk->vtbl[1005] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1005]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1005].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1005].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1005@_QIThunk@ATL@@UEAAJXZ


	.global ?f1006@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1006@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1006@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1006*8,r14	// r14 = &m_pUnk->vtbl[1006] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1006]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1006].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1006].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1006@_QIThunk@ATL@@UEAAJXZ


	.global ?f1007@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1007@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1007@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1007*8,r14	// r14 = &m_pUnk->vtbl[1007] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1007]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1007].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1007].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1007@_QIThunk@ATL@@UEAAJXZ


	.global ?f1008@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1008@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1008@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1008*8,r14	// r14 = &m_pUnk->vtbl[1008] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1008]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1008].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1008].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1008@_QIThunk@ATL@@UEAAJXZ


	.global ?f1009@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1009@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1009@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1009*8,r14	// r14 = &m_pUnk->vtbl[1009] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1009]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1009].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1009].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1009@_QIThunk@ATL@@UEAAJXZ


	.global ?f1010@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1010@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1010@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1010*8,r14	// r14 = &m_pUnk->vtbl[1010] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1010]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1010].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1010].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1010@_QIThunk@ATL@@UEAAJXZ


	.global ?f1011@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1011@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1011@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1011*8,r14	// r14 = &m_pUnk->vtbl[1011] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1011]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1011].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1011].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1011@_QIThunk@ATL@@UEAAJXZ


	.global ?f1012@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1012@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1012@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1012*8,r14	// r14 = &m_pUnk->vtbl[1012] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1012]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1012].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1012].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1012@_QIThunk@ATL@@UEAAJXZ


	.global ?f1013@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1013@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1013@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1013*8,r14	// r14 = &m_pUnk->vtbl[1013] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1013]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1013].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1013].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1013@_QIThunk@ATL@@UEAAJXZ


	.global ?f1014@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1014@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1014@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1014*8,r14	// r14 = &m_pUnk->vtbl[1014] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1014]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1014].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1014].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1014@_QIThunk@ATL@@UEAAJXZ


	.global ?f1015@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1015@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1015@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1015*8,r14	// r14 = &m_pUnk->vtbl[1015] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1015]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1015].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1015].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1015@_QIThunk@ATL@@UEAAJXZ


	.global ?f1016@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1016@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1016@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1016*8,r14	// r14 = &m_pUnk->vtbl[1016] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1016]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1016].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1016].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1016@_QIThunk@ATL@@UEAAJXZ


	.global ?f1017@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1017@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1017@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1017*8,r14	// r14 = &m_pUnk->vtbl[1017] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1017]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1017].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1017].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1017@_QIThunk@ATL@@UEAAJXZ


	.global ?f1018@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1018@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1018@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1018*8,r14	// r14 = &m_pUnk->vtbl[1018] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1018]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1018].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1018].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1018@_QIThunk@ATL@@UEAAJXZ


	.global ?f1019@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1019@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1019@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1019*8,r14	// r14 = &m_pUnk->vtbl[1019] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1019]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1019].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1019].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1019@_QIThunk@ATL@@UEAAJXZ


	.global ?f1020@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1020@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1020@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1020*8,r14	// r14 = &m_pUnk->vtbl[1020] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1020]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1020].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1020].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1020@_QIThunk@ATL@@UEAAJXZ


	.global ?f1021@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1021@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1021@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1021*8,r14	// r14 = &m_pUnk->vtbl[1021] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1021]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1021].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1021].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1021@_QIThunk@ATL@@UEAAJXZ


	.global ?f1022@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1022@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1022@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1022*8,r14	// r14 = &m_pUnk->vtbl[1022] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1022]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1022].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1022].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1022@_QIThunk@ATL@@UEAAJXZ


	.global ?f1023@_QIThunk@ATL@@UEAAJXZ
	.proc	?f1023@_QIThunk@ATL@@UEAAJXZ
	.align	32

?f1023@_QIThunk@ATL@@UEAAJXZ:
		add				r16=16,r32		// r16 = &m_dwRef
		ld4				r16=[r16]		// r16 = m_dwRef
		cmp.le			p6,p7=r16,r0	// p6 = m_dwRef
(p6)	break.i			0x80016			// Break if call through deleted thunk
		add				r32=8,r32		// r32 = &m_pUnk 
		ld8				r32=[r32]		// r32 = m_pUnk 
		ld8				r14=[r32]		// r14 = m_pUnk->vtbl 
		add				r14=1023*8,r14	// r14 = &m_pUnk->vtbl[1023] 
		ld8				r14=[r14]		// r14 = m_pUnk->vtbl[1023]
		ld8				r15=[r14],8		// r15 = m_pUnk->vtbl[1023].pfn,
		ld8				gp=[r14]		// gp = m_pUnk->vtbl[1023].gp 
		mov				b6=r15
		br.sptk.many	b6				// Forward to actual call site 
	.endp	?f1023@_QIThunk@ATL@@UEAAJXZ

