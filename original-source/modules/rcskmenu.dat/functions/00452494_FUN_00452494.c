/*
 * FUN_00452494 at 00452494
 * undefined FUN_00452494(void)
 * Address ranges: 00452494-004524e1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00452494(int *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 < 1) {
    FUN_00451c90(param_1,param_2,param_3);
    return;
  }
  cVar1 = (**(code **)(*param_1 + 0x1c))();
  if (cVar1 == '\0') {
    FUN_00452624(param_1,param_2,param_1[0x10],param_1[0xf]);
  }
  else {
    iVar3 = 8;
    iVar2 = FUN_004502cc(param_1[0x10],1);
    FUN_00452624(param_1,param_2,iVar2,iVar3);
  }
  return;
}

