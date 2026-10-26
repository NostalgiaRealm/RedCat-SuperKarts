/*
 * FUN_004491e4 at 004491e4
 * int __register FUN_004491e4(int param_1, int param_2, undefined4 param_3)
 * Address ranges: 004491e4-00449227
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004491e4(int param_1,int param_2,undefined4 param_3)

{
  undefined4 extraout_ECX;
  int local_c;
  
  if (*(int *)(param_2 + 0xc) == 0) {
    local_c = FUN_00447264(param_2);
    local_c = local_c + *(int *)(param_2 + 0x20);
    param_3 = extraout_ECX;
  }
  else {
    local_c = *(int *)(*(int *)(param_2 + 0xc) + 0x20);
  }
  FUN_00449168(*(int *)(*(int *)(param_1 + 100) + 8),param_2,param_3,(int)&stack0xfffffffc);
  return local_c;
}

