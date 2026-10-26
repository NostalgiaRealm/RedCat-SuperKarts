/*
 * FUN_00440370 at 00440370
 * char __register FUN_00440370(int * param_1, undefined4 * param_2)
 * Address ranges: 00440370-0044040e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char FUN_00440370(int *param_1,undefined4 *param_2)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_2c [4];
  undefined4 auStack_1c [4];
  
  puVar6 = local_2c;
  for (iVar5 = 4; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *param_2;
    param_2 = param_2 + 1;
    puVar6 = puVar6 + 1;
  }
  if ((int *)param_1[0x24] != (int *)0x0) {
    cVar1 = FUN_00403088((int *)param_1[0x24],0,param_1);
    if (cVar1 == '\0') {
      cVar1 = '\0';
      goto LAB_004403a8;
    }
  }
  cVar1 = '\x01';
LAB_004403a8:
  if (cVar1 != '\0') {
    piVar2 = FUN_00440fe8(param_1,local_2c);
    if (piVar2 == (int *)0x0) {
      FUN_00403088(param_1,0,local_2c);
    }
    else {
      uVar3 = FUN_0043f0f4(piVar2);
      puVar6 = auStack_1c;
      uVar4 = FUN_0043f0b0(piVar2);
      FUN_0040ebe8(0,0,uVar4,puVar6,uVar3);
      FUN_00403088(param_1,piVar2,auStack_1c);
    }
  }
  return cVar1;
}

