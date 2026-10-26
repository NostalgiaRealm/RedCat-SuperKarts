/*
 * FUN_0043a6a0 at 0043a6a0
 * undefined __register FUN_0043a6a0(int * param_1)
 * Address ranges: 0043a6a0-0043a6e6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043a6a0(int *param_1)

{
  HANDLE pvVar1;
  
  if ((PTR_DAT_0047c9d8[9] != '\0') && (*(char *)((int)param_1 + 0x35) != '\0')) {
    pvVar1 = FUN_00435898((POINT *)(param_1 + 0x12));
    if (pvVar1 == (HANDLE)0x0) {
      FUN_00439e64(param_1,*(char *)(*(int *)PTR_DAT_0047c86c + 0x28));
      *(undefined1 *)((int)param_1 + 0x35) = 1;
    }
    else {
      FUN_00439e64(param_1,*(char *)((int)pvVar1 + 0x4f));
      *(undefined1 *)((int)param_1 + 0x35) = 1;
    }
  }
  return;
}

