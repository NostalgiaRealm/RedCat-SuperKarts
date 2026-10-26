/*
 * FUN_0048c7e0 at 0048c7e0
 * undefined FUN_0048c7e0(void)
 * Address ranges: 0048c7e0-0048c999
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048c7e0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_14;
  int local_10;
  
  *(undefined4 *)(param_1 + 0x1184) = 0;
  *(undefined4 *)(param_1 + 0x1188) = 0;
  *(undefined4 *)(param_1 + 0x1180) = 0;
  *(undefined4 *)(param_1 + 0x1190) = 0;
  *(undefined4 *)(param_1 + 0x1194) = 0;
  *(undefined4 *)(param_1 + 0x118c) = 0;
  *(undefined1 *)(param_1 + 0x1198) = 1;
  DAT_0067e470 = FUN_004a6060(s_S_SFX_PCX_004fa13c);
  *(undefined4 *)(param_1 + 0x11a4) = 7;
  uVar4 = 10;
  local_14 = 0x3c;
  uVar5 = 0xaa;
  puVar2 = (undefined4 *)(param_1 + 0x1c);
  local_10 = 0x14;
  do {
    puVar2[-1] = 0x3efc0000;
    *puVar2 = 0x3f7c0000;
    puVar2[7] = 0x3efc0000;
    puVar2[8] = 0x3efc0000;
    puVar2[0xf] = 0x3f7c0000;
    puVar2[0x10] = 0x3f7c0000;
    puVar2[0x17] = 0x3f7c0000;
    puVar2[0x18] = 0x3efc0000;
    puVar2[0x1f] = 0x3f7c0000;
    puVar2[0x20] = 0x3f7c0000;
    puVar2[0x27] = 0x3efc0000;
    puVar2[0x28] = 0x3efc0000;
    puVar2[0x2f] = 0x3efc0000;
    puVar2[0x30] = 0x3f7c0000;
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x11a4)) {
      puVar1 = puVar2 + -2;
      do {
        uVar4 = uVar4 + 0x2d;
        if (0xff < (int)uVar4) {
          uVar4 = 0;
        }
        local_14 = local_14 + 0x41;
        if (0xff < (int)local_14) {
          local_14 = 0;
        }
        uVar5 = uVar5 + 0x55;
        if (0xff < (int)uVar5) {
          uVar5 = 0;
        }
        iVar3 = iVar3 + 1;
        puVar1[-1] = ((uVar4 | 0xffffff00) << 8 | local_14) << 8 | uVar5;
        *puVar1 = 0;
        puVar1 = puVar1 + 8;
      } while (iVar3 < *(int *)(param_1 + 0x11a4));
    }
    puVar2 = puVar2 + 0x38;
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  *(undefined4 *)(param_1 + 0x11a8) = 0;
  FUN_0048c520();
  return;
}

