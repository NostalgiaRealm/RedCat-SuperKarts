/*
 * FUN_00444a14 at 00444a14
 * undefined __register FUN_00444a14(int * param_1)
 * Address ranges: 00444a14-00444a47
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444a14(int *param_1)

{
  (**(code **)(*param_1 + -0x10))();
  RemovePropA((HWND)param_1[0x53],(LPCSTR)(uint)DAT_0047d7b6);
  RemovePropA((HWND)param_1[0x53],(LPCSTR)(uint)DAT_0047d7b4);
  return;
}

