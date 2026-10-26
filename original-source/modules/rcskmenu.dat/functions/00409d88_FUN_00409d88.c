/*
 * FUN_00409d88 at 00409d88
 * int __register FUN_00409d88(int param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 00409d88-00409de2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00409d88(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  WORD WVar1;
  uint uVar2;
  
  if (DAT_0047d5b4 == 0x12) {
    if (param_1 < 100) {
      WVar1 = FUN_00408f40();
      uVar2 = (int)*(uint *)(param_4 + -4) >> 0x1f;
      param_1 = param_1 + ((int)((uint)WVar1 + ((*(uint *)(param_4 + -4) ^ uVar2) - uVar2)) / 100) *
                          100;
    }
    if (0 < *(int *)(param_4 + -4)) {
      *(int *)(param_4 + -4) = -*(int *)(param_4 + -4);
    }
  }
  else {
    *(int *)(param_4 + -4) = *(int *)(param_4 + -4) + -1;
  }
  return *(int *)(param_4 + -4) + param_1;
}

