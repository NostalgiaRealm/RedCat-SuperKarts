/*
 * FUN_0041ce40 at 0041ce40
 * uint __register FUN_0041ce40(int * param_1)
 * Address ranges: 0041ce40-0041ce84
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_0041ce40(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  if (param_1[0xb] == 0x20000000) {
    uVar1 = FUN_0041ce10((int)param_1);
    if ((char)uVar1 == '\0') {
      iVar3 = (**(code **)(*param_1 + 0x20))();
      piVar4 = (int *)FUN_0041cd5c(param_1);
      uVar2 = FUN_00418920(piVar4,0,iVar3 + -1);
    }
    else {
      uVar2 = 0xffffff;
    }
  }
  else {
    uVar2 = FUN_00417210(param_1[0xb]);
  }
  return uVar2 | 0x2000000;
}

