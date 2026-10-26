/*
 * FUN_004293e8 at 004293e8
 * undefined __register FUN_004293e8(undefined4 * param_1)
 * Address ranges: 004293e8-0042941e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004293e8(undefined4 *param_1)

{
  undefined4 *puVar1;
  BOOL BVar2;
  
  while (param_1 != (undefined4 *)0x0) {
    BVar2 = IsWindow((HWND)param_1[1]);
    if (BVar2 != 0) {
      EnableWindow((HWND)param_1[1],-1);
    }
    puVar1 = (undefined4 *)*param_1;
    FUN_0040272c((int)param_1);
    param_1 = puVar1;
  }
  return;
}

