; This is a part of the Active Template Library.
; Copyright (C) Microsoft Corporation
; All rights reserved.
;
; This source code is only intended as a supplement to the
; Active Template Library Reference and related
; electronic documentation provided with the library.
; See these sources for detailed information regarding the	
; Active Template Library product.


IMPL_QITHUNK MACRO num

	PUBLIC	?f&num&@_QIThunk@ATL@@UEAAJXZ

?f&num&@_QIThunk@ATL@@UEAAJXZ PROC

		cmp qword ptr [rcx+16], 0;		; compare m_dwRef to 0 ( rcx points to the _QIThunk )
		jg goodref;						; if it is greater than 0, the reference count is OK
		int 3;							; Break if call through deleted thunk
goodref:
		mov rax, qword ptr [rcx+8];		; rax = _QIThunk->pUnk
		mov rcx, rax;					; replace the 1st parameter (this) with _QIThunk->pUnk
		mov rax, qword ptr [rax];		; rax = _QIThunk->pUnk->vTable
		jmp qword ptr [rax+8*&num&];	; jump to the nth function in the vTable

?f&num&@_QIThunk@ATL@@UEAAJXZ ENDP

ENDM

_TEXT	SEGMENT

; the code below uses the IMPL_QITHUNK macro to generate functions f3@... to f1023@...

ordinal = 3
WHILE ordinal LE 1023
	IMPL_QITHUNK %ordinal%
	ordinal = ordinal + 1
ENDM

_TEXT	ENDS

END