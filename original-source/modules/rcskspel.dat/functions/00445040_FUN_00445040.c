/*
 * FUN_00445040 at 00445040
 * undefined FUN_00445040(void)
 * Address ranges: 00445040-004450b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445040(void)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < DAT_00543760) {
    piVar3 = &DAT_0053f668;
    do {
      iVar1 = *piVar3;
      cVar2 = FUN_00446b80(iVar1);
      if (cVar2 == '\0') {
        if (*(code **)(&DAT_004ef058 + iVar1 * 0x14) != (code *)0x0) {
          (**(code **)(&DAT_004ef058 + iVar1 * 0x14))(iVar4);
        }
      }
      else {
        FUN_00447290(iVar4);
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 0xd0;
    } while (iVar4 < DAT_00543760);
  }
  FUN_004afce0(s__s__d____Unloading_CPathControll_004ef320,
               s_D__work_rcsk_Code_game_pth_main__004ef2fc,0xf2);
  FUN_00446170();
  FUN_00446b10();
  return;
}

