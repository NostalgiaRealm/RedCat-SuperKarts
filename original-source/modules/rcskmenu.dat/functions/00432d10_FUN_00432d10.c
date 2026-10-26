/*
 * FUN_00432d10 at 00432d10
 * undefined __register FUN_00432d10(int param_1, int * param_2, int param_3)
 * Address ranges: 00432d10-00432e1b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432d10(int param_1,int *param_2,int param_3)

{
  POINT pt;
  int *piVar1;
  int iVar2;
  BOOL BVar3;
  undefined4 extraout_EDX;
  UINT local_30;
  byte local_2c;
  tagPOINT local_28;
  POINT local_20;
  int local_18 [2];
  
  FUN_00406c20(*(undefined4 *)(param_3 + 8),local_18);
  FUN_0043f1c4(param_2,local_18,&local_20.x);
  piVar1 = FUN_0043e0b0(&local_20,CONCAT31((int3)((uint)extraout_EDX >> 8),1));
  iVar2 = thunk_FUN_00430ca9((int)piVar1);
  if ((iVar2 == 0) || (*(char *)(iVar2 + 0x89) == '\0')) {
    FUN_00432e8c(param_1);
  }
  else {
    if (iVar2 == *(int *)(param_1 + 0x50)) {
      FUN_00406c20(*(undefined4 *)(param_3 + 8),local_18);
      FUN_0043f1c4(param_2,local_18,&local_20.x);
      pt.y = local_20.y;
      pt.x = local_20.x;
      BVar3 = PtInRect((RECT *)(param_1 + 0x54),pt);
      if (BVar3 != 0) {
        return;
      }
    }
    local_2c = *(byte *)(param_1 + 0x48);
    if (local_2c == 0) {
      local_30 = *(UINT *)(param_1 + 0x68);
    }
    else {
      local_30 = *(UINT *)(param_1 + 0x70);
    }
    FUN_004405f0(iVar2,0xb041,(uint)local_2c,&local_30);
    if ((local_2c == 0) || (local_30 != 0)) {
      FUN_00432e8c(param_1);
      *(byte *)(param_1 + 0x48) = local_2c;
      *(int *)(param_1 + 0x50) = iVar2;
      FUN_00432cb8(param_1,local_30,0);
    }
    else {
      *(byte *)(param_1 + 0x48) = local_2c;
      *(int *)(param_1 + 0x50) = iVar2;
      GetCursorPos(&local_28);
      FUN_0043306c(param_1,&local_28.x);
    }
  }
  return;
}

