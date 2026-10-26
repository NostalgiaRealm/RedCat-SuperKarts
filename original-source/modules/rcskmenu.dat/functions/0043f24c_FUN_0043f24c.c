/*
 * FUN_0043f24c at 0043f24c
 * undefined __register FUN_0043f24c(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 * Address ranges: 0043f24c-0043f2ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f24c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (((*(int *)(param_1 + 0x90) != 0) && (DAT_0047d7bc == 0)) &&
     ((*(ushort *)(param_1 + 0x20) & 9) == 0)) {
    local_c = param_4;
    local_14 = param_2;
    local_10 = param_3;
    local_8 = param_3;
    FUN_004405f0(*(int *)(param_1 + 0x90),0xb042,param_1,&local_14);
  }
  return;
}

