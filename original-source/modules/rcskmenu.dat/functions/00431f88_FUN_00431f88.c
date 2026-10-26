/*
 * FUN_00431f88 at 00431f88
 * bool __register FUN_00431f88(int param_1, LPMSG param_2)
 * Address ranges: 00431f88-00431fab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00431f88(int param_1,LPMSG param_2)

{
  BOOL BVar1;
  bool bVar2;
  
  bVar2 = false;
  if (*(HWND *)(param_1 + 0xa0) != (HWND)0x0) {
    BVar1 = IsDialogMessageA(*(HWND *)(param_1 + 0xa0),param_2);
    bVar2 = BVar1 != 0;
  }
  return bVar2;
}

