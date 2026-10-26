/*
 * FUN_00446ee4 at 00446ee4
 * bool __register FUN_00446ee4(int * param_1, HWND param_2, int param_3, int param_4)
 * Address ranges: 00446ee4-00446f43
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00446ee4(int *param_1,HWND param_2,int param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  
  bVar2 = false;
  bVar1 = FUN_00433874((int)param_1);
  if (bVar1) {
    if (*(char *)((int)param_1 + 0x62) == '\0') {
      FUN_00446e84(param_1,param_1[0x1c],param_1[0x1a],param_1[0x1b]);
    }
    FUN_00446db8((int)param_1);
    bVar2 = FUN_00446f44((int)param_1,param_2,param_3,param_4);
    if (bVar2) {
      ShowCursor(0);
    }
  }
  return bVar2;
}

