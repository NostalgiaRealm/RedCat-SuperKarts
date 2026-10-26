/*
 * FUN_0049b0a0 at 0049b0a0
 * undefined FUN_0049b0a0(void)
 * Address ranges: 0049b0a0-0049b125
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049b0a0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = DAT_006847d4;
  if (0 < DAT_006847d4) {
    do {
      puVar1 = *(undefined4 **)(DAT_006847d0 + iVar3 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
        iVar2 = DAT_006847d4;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  if (DAT_006847dc == 1) {
    FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006847fd,&DAT_006847e4,iVar2);
    FUN_004bc150(DAT_006847d0);
  }
  if (DAT_006847dc != 0) {
    FUN_004bc150(DAT_006847e0);
    DAT_006847dc = 0;
  }
  FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  return;
}

