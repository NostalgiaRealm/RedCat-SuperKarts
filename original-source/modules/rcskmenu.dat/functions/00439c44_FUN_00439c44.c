/*
 * FUN_00439c44 at 00439c44
 * undefined __register FUN_00439c44(undefined4 param_1, int param_2)
 * Address ranges: 00439c44-00439dbb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00439c44(undefined4 param_1,int param_2)

{
  UINT UVar1;
  char cVar2;
  int iVar3;
  UINT UVar4;
  undefined4 uVar5;
  UINT UVar6;
  int local_1c;
  UINT local_18;
  UINT local_14;
  UINT local_10;
  
  *(undefined4 *)(param_2 + 0xc) = 0;
  local_10 = 0xffffffff;
  local_14 = 0xffffffff;
  local_18 = 0xffffffff;
  iVar3 = GetMenuItemCount(*(HMENU *)(param_2 + 8));
  if (-1 < iVar3 + -1) {
    UVar6 = 0;
    local_1c = iVar3;
    do {
      UVar4 = GetMenuState(*(HMENU *)(param_2 + 8),UVar6,0x400);
      uVar5 = FUN_00439b00(*(HMENU *)(param_2 + 8),UVar4,UVar6,*(byte *)(param_2 + 4),
                           (int)&stack0xfffffffc);
      UVar1 = local_14;
      if ((char)uVar5 != '\0') {
        if ((UVar4 & 2) == 0) {
          if ((int)local_10 < 0) {
            *(undefined4 *)(param_2 + 0xc) = 2;
            local_10 = UVar6;
          }
          else {
            *(undefined4 *)(param_2 + 0xc) = 3;
          }
          UVar1 = UVar6;
          if (((UVar4 & 0x80) == 0) && (UVar1 = local_14, -1 < (int)local_14)) {
            local_18 = UVar6;
          }
        }
        else if ((int)local_10 < 0) {
          local_10 = 0xfffffffe;
        }
      }
      local_14 = UVar1;
      UVar6 = UVar6 + 1;
      local_1c = local_1c + -1;
    } while (local_1c != 0);
  }
  if ((int)local_10 < -1) {
    *(undefined4 *)(param_2 + 0xc) = 0x10000;
  }
  else {
    if (((int)local_10 < 0) && (-1 < iVar3 + -1)) {
      UVar6 = 0;
      local_1c = iVar3;
      do {
        UVar4 = GetMenuState(*(HMENU *)(param_2 + 8),UVar6,0x400);
        cVar2 = FUN_00439b5c(*(HMENU *)(param_2 + 8),(ushort)UVar4,UVar6,
                             *(undefined1 *)(param_2 + 4),(int)&stack0xfffffffc);
        UVar1 = local_14;
        if (cVar2 != '\0') {
          if ((UVar4 & 2) != 0) {
            *(undefined4 *)(param_2 + 0xc) = 0x10000;
            return;
          }
          if ((int)local_10 < 0) {
            *(undefined4 *)(param_2 + 0xc) = 2;
            local_10 = UVar6;
          }
          else {
            *(undefined4 *)(param_2 + 0xc) = 3;
          }
          UVar1 = UVar6;
          if (((UVar4 & 0x80) == 0) && (UVar1 = local_14, -1 < (int)local_14)) {
            local_18 = UVar6;
          }
        }
        local_14 = UVar1;
        UVar6 = UVar6 + 1;
        local_1c = local_1c + -1;
      } while (local_1c != 0);
    }
    if (*(int *)(param_2 + 0xc) == 2) {
      *(UINT *)(param_2 + 0xc) = local_10 | 0x20000;
    }
    else if (*(int *)(param_2 + 0xc) == 3) {
      if ((int)local_18 < 0) {
        local_18 = local_10;
      }
      *(UINT *)(param_2 + 0xc) = local_18 | 0x30000;
    }
  }
  return;
}

