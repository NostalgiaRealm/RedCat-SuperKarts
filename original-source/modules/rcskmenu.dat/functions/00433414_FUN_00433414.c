/*
 * FUN_00433414 at 00433414
 * char __register FUN_00433414(int param_1, undefined4 param_2, int * param_3)
 * Address ranges: 00433414-004334a2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char FUN_00433414(int param_1,undefined4 param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_EDX;
  
  iVar3 = *(int *)(DAT_0047d774 + 0x60);
  if (iVar3 == 0) {
LAB_0043343f:
    iVar2 = *(int *)(param_1 + 0x38);
    if ((iVar3 != iVar2) && (iVar2 != 0)) {
      iVar3 = FUN_004405f0(iVar2,param_2,0,param_3);
      if (iVar3 == 1) goto LAB_0043345f;
    }
    cVar1 = '\0';
  }
  else {
    iVar2 = FUN_004405f0(iVar3,param_2,0,param_3);
    if (iVar2 != 1) goto LAB_0043343f;
LAB_0043345f:
    cVar1 = '\x01';
  }
  if (cVar1 == '\0') {
    uVar4 = FUN_00403024(param_3,(int)&PTR_FUN_0042618c);
    if ((((char)uVar4 != '\0') && (*(char *)((int)param_3 + 0x59) != '\0')) &&
       ((char)param_3[0x14] != '\0')) {
      FUN_00426a80(param_3,CONCAT31((int3)((uint)extraout_EDX >> 8),
                                    *(short *)((int)param_3 + 0x32) != 0));
    }
  }
  return cVar1;
}

