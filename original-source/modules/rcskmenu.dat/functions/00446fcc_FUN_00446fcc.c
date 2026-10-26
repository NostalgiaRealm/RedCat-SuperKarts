/*
 * FUN_00446fcc at 00446fcc
 * bool __register FUN_00446fcc(int param_1, int param_2, int param_3)
 * Address ranges: 00446fcc-0044700e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00446fcc(int param_1,int param_2,int param_3)

{
  bool bVar1;
  BOOL BVar2;
  int local_14;
  int local_10;
  
  bVar1 = FUN_00433874(param_1);
  if (bVar1) {
    FUN_00446d78(*(HWND *)(param_1 + 100),param_2,param_3,&local_14);
    BVar2 = ImageList_DragMove(local_14,local_10);
    bVar1 = BVar2 != 0;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

