/*
 * FUN_00437b44 at 00437b44
 * undefined FUN_00437b44(void)
 * Address ranges: 00437b44-00437c5b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00437b44(int *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 ushort param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 auStack_24 [8];
  
  puVar4 = auStack_24;
  for (iVar3 = 4; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_3;
    param_3 = param_3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar3 = thunk_FUN_004385f4((int)param_1);
  iVar1 = FUN_00437c5c((int)param_1);
  if (((iVar3 == 0) || ((*(char *)(iVar3 + 0x34) == '\0' && (iVar1 == 0)))) ||
     ((*(short *)((int)param_1 + 0x92) == 0 && (*(short *)((int)param_1 + 0x8a) == 0)))) {
    if ((iVar3 == 0) || (uVar2 = FUN_00439ae8(iVar3), (char)uVar2 != '\0')) {
      FUN_0043729c();
    }
    else {
      FUN_00436a1c();
    }
  }
  else {
    (**(code **)(*param_1 + 0x34))(param_1,param_2,auStack_24,(param_5 & 1) != 0);
    if (*(short *)((int)param_1 + 0x92) != 0) {
      (*(code *)param_1[0x24])
                (param_1[0x25],param_1,param_2,CONCAT22((short)((uint)auStack_24 >> 0x10),param_5),
                 auStack_24);
    }
  }
  return;
}

