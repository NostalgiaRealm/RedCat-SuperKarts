/*
 * FUN_0042c4d0 at 0042c4d0
 * undefined FUN_0042c4d0(void)
 * Address ranges: 0042c4d0-0042c56b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042c4d0(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_84 [32];
  undefined1 local_64 [100];
  
  FUN_004b1d60(s_Race_ini_004ea030);
  if (DAT_0053be50 != 0) {
    FUN_00417d00();
    iVar4 = 0;
    if (0 < DAT_00508610) {
      puVar3 = &DAT_005081b4;
      do {
        FUN_004bea92(local_84,&DAT_004ea03c,iVar4);
        cVar1 = FUN_00417e90(iVar4);
        uVar2 = DAT_0053be60;
        if (cVar1 == '\0') {
          uVar2 = puVar3[1];
        }
        FUN_004bea92(local_64,s__d__d__d_004ea040,puVar3[-1],uVar2,*puVar3);
        FUN_004b1e30(s_RACERS_004ea04c,local_84,local_64);
        iVar4 = iVar4 + 1;
        puVar3 = puVar3 + 0x1c;
      } while (iVar4 < DAT_00508610);
    }
  }
  return;
}

