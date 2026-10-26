/*
 * FUN_00440a6c at 00440a6c
 * undefined __register FUN_00440a6c(int * param_1, int param_2)
 * Address ranges: 00440a6c-00440ab9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440a6c(int *param_1,int param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  
  FUN_0043f21c(param_1,param_1);
  (**(code **)(*param_1 + -0x10))(param_1,param_2);
  uVar1 = extraout_ECX;
  uVar2 = extraout_EDX;
  if ((*(byte *)(param_1 + 0x10) & 2) != 0) {
    FUN_0043f868(param_1,'\x01');
    uVar1 = extraout_ECX_00;
    uVar2 = extraout_EDX_00;
  }
  if ((*(byte *)(param_1 + 0x10) & 8) != 0) {
    FUN_00403088(param_1,uVar2,uVar1);
  }
  FUN_004409c0(param_1,param_2,0,0x40);
  return;
}

