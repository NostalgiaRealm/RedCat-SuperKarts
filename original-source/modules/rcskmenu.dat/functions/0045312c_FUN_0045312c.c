/*
 * FUN_0045312c at 0045312c
 * undefined __register FUN_0045312c(int param_1, int param_2, int param_3, int param_4, int param_5)
 * Address ranges: 0045312c-0045316f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045312c(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  HRGN hrgnSrc2;
  
  hrgnSrc2 = CreateRectRgn(param_1,param_2,param_3,param_4);
  if (*(int *)(param_5 + -4) == 0) {
    *(HRGN *)(param_5 + -4) = hrgnSrc2;
  }
  else {
    CombineRgn(*(HRGN *)(param_5 + -4),*(HRGN *)(param_5 + -4),hrgnSrc2,2);
    DeleteObject(hrgnSrc2);
  }
  return;
}

