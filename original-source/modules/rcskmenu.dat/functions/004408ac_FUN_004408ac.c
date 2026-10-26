/*
 * FUN_004408ac at 004408ac
 * undefined __register FUN_004408ac(undefined4 param_1, int * param_2)
 * Address ranges: 004408ac-004408e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004408ac(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  pcVar3 = FUN_0044085c;
  pcVar2 = FUN_00440870;
  uVar4 = param_1;
  uVar1 = FUN_0044087c();
  (**(code **)(*param_2 + 4))(param_2,"IsControl",uVar1,pcVar2,param_1,pcVar3,uVar4);
  return;
}

