/*
 * FUN_00439e88 at 00439e88
 * undefined __register FUN_00439e88(int * param_1)
 * Address ranges: 00439e88-00439eac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00439e88(int *param_1)

{
  HANDLE pvVar1;
  
  if (*(char *)((int)param_1 + 0x35) != '\0') {
    pvVar1 = FUN_0043c864((HWND)param_1[0xb]);
    if (pvVar1 != (HANDLE)0x0) {
      FUN_00439e64(param_1,*(char *)((int)pvVar1 + 0x4f));
      *(undefined1 *)((int)param_1 + 0x35) = 1;
    }
  }
  return;
}

