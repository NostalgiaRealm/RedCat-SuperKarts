/*
 * FUN_0043e3ac at 0043e3ac
 * undefined __register FUN_0043e3ac(int * param_1)
 * Address ranges: 0043e3ac-0043e3dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e3ac(int *param_1)

{
  if (param_1[0x17] != 0) {
    FUN_00418a14(param_1,0);
    FUN_0040fa84(DAT_0047d7e8,(int)param_1);
    ReleaseDC((HWND)param_1[0x18],(HDC)param_1[0x17]);
    param_1[0x17] = 0;
  }
  return;
}

