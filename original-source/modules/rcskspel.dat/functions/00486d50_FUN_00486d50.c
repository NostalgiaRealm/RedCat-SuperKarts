/*
 * FUN_00486d50 at 00486d50
 * undefined FUN_00486d50(void)
 * Address ranges: 00486d50-00486e92
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00486d50(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int local_8;
  int local_4;
  
  *(int *)(param_1 + 0x784) = *(int *)(param_1 + 0x784) + 10;
  *(int *)(param_1 + 0x788) = *(int *)(param_1 + 0x788) + 10;
  *(int *)(param_1 + 0x78c) = *(int *)(param_1 + 0x78c) + 10;
  local_8 = 0;
  if (0 < *(int *)(param_1 + 0x770)) {
    local_4 = 0;
    do {
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0x734)) {
        do {
          iVar2 = *(int *)(param_1 + 0x784 + iVar3 * 4);
          iVar1 = iVar3 + 1;
          uVar4 = iVar1 * iVar2;
          iVar5 = (local_4 + iVar3) * 0x20 + param_1;
          *(uint *)(iVar5 + 0x10) =
               (((local_8 + iVar3) * iVar2 | 0xffffc800U) << 8 | (local_8 + 1) * uVar4) << 8 | uVar4
          ;
          *(undefined4 *)(iVar5 + 0x14) = 0x64000000;
          if (iVar3 == 2) {
            uVar4 = __ftol();
            *(uint *)(local_4 * 0x20 + 0x350 + param_1) = (uVar4 | 0xffffc800) << 0x10;
          }
          else {
            *(undefined4 *)(iVar5 + 0x310) = 0xc8ff0000;
          }
          *(undefined4 *)(iVar5 + 0x314) = 0x64000000;
          iVar3 = iVar1;
        } while (iVar1 < *(int *)(param_1 + 0x734));
      }
      local_8 = local_8 + 1;
      local_4 = local_4 + 3;
    } while (local_8 < *(int *)(param_1 + 0x770));
  }
  return;
}

