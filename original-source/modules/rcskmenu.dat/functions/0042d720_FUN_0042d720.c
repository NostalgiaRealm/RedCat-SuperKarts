/*
 * FUN_0042d720 at 0042d720
 * undefined __register FUN_0042d720(int param_1, undefined4 param_2)
 * Address ranges: 0042d720-0042d76f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042d720(int param_1,undefined4 param_2)

{
  HANDLE pvVar1;
  
  if ((*(char *)(param_1 + 0x216) != '\0') && (*(int *)(param_1 + 0x208) != 0)) {
    FUN_004405f0(*(int *)(param_1 + 0x208),0xb004,0,param_2);
  }
  if (*(char *)(param_1 + 0x217) == '\x02') {
    pvVar1 = FUN_0042c44c(param_1);
    if (pvVar1 != (HANDLE)0x0) {
      pvVar1 = FUN_0042c44c(param_1);
      FUN_0042d720((int)pvVar1,param_2);
    }
  }
  return;
}

