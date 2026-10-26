/*
 * FUN_00431398 at 00431398
 * undefined4 __register FUN_00431398(void)
 * Address ranges: 00431398-00431406
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00431398(void)

{
  HWND pHVar1;
  uint uVar2;
  undefined4 uVar3;
  HWND in_stack_00000004;
  undefined4 *in_stack_00000008;
  
  uVar3 = 0xffffffff;
  pHVar1 = GetWindow(in_stack_00000004,4);
  if (pHVar1 == *(HWND *)(DAT_0047d770 + 0x24)) {
    uVar2 = GetWindowLongA(in_stack_00000004,-0x14);
    if (((uVar2 & 8) == 0) ||
       (((*(int **)(DAT_0047d770 + 0x38) != (int *)0x0 && (*(char *)(in_stack_00000008 + 1) == '\0')
         ) && (pHVar1 = (HWND)FUN_00445724(*(int **)(DAT_0047d770 + 0x38)),
              in_stack_00000004 == pHVar1)))) {
      *in_stack_00000008 = in_stack_00000004;
      uVar3 = 0;
    }
    else {
      FUN_0040f504(*(int **)(DAT_0047d770 + 0x80),(int)in_stack_00000004);
    }
    return uVar3;
  }
  return 0xffffffff;
}

