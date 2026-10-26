/*
 * FUN_00443b74 at 00443b74
 * undefined __register FUN_00443b74(int * param_1, undefined4 param_2)
 * Address ranges: 00443b74-00443ba4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00443b74(int *param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  FUN_00445a2c((int)param_1);
  (**(code **)(*param_1 + -0x10))(param_1,param_2);
  FUN_0044221c(param_1);
  if ((*(byte *)(param_1 + 8) & 1) == 0) {
    FUN_00403088(param_1,extraout_EDX,extraout_ECX);
  }
  return;
}

