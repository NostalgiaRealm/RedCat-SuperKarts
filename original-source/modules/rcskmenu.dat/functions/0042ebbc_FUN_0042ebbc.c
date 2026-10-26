/*
 * FUN_0042ebbc at 0042ebbc
 * undefined FUN_0042ebbc(void)
 * Address ranges: 0042ebbc-0042ec1e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_0042ebbc(int param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uStack_10;
  
  uStack_10 = param_3;
  if (*(char *)(param_1 + 0x217) == '\x02') {
    uStack_10 = param_3 & 0xffffff00;
    iVar2 = FUN_0042c480(param_1);
    if (-1 < iVar2 + -1) {
      iVar4 = 0;
      do {
        piVar3 = (int *)FUN_0042c4cc(param_1,iVar4);
        cVar1 = (**(code **)(*piVar3 + 0xd0))();
        if (cVar1 == '\0') goto LAB_0042ec17;
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  uStack_10 = CONCAT31(uStack_10._1_3_,1);
  if (*(short *)(param_1 + 0x282) != 0) {
    (**(code **)(param_1 + 0x280))(*(undefined4 *)(param_1 + 0x284),param_1,&uStack_10);
  }
LAB_0042ec17:
  return uStack_10 & 0xff;
}

