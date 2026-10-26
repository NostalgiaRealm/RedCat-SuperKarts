/*
 * FUN_00446f44 at 00446f44
 * bool __register FUN_00446f44(int param_1, HWND param_2, int param_3, int param_4)
 * Address ranges: 00446f44-00446fa4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00446f44(int param_1,HWND param_2,int param_3,int param_4)

{
  bool bVar1;
  BOOL BVar2;
  bool bVar3;
  int local_10;
  int local_c;
  int local_8;
  
  bVar3 = false;
  local_8 = param_3;
  bVar1 = FUN_00433874(param_1);
  if ((bVar1) && (param_2 != *(HWND *)(param_1 + 100))) {
    FUN_00446fa8(param_1);
    *(HWND *)(param_1 + 100) = param_2;
    FUN_00446d78(param_2,local_8,param_4,&local_10);
    BVar2 = ImageList_DragEnter(*(HWND *)(param_1 + 100),local_10,local_c);
    bVar3 = BVar2 != 0;
  }
  return bVar3;
}

