/*
 * FUN_00402940 at 00402940
 * undefined __stdcall FUN_00402940(void)
 * Address ranges: 00402940-004029f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402940(void)

{
  int in_EAX;
  int iVar1;
  HPALETTE pHVar2;
  int iVar3;
  uint uVar4;
  LOGPALETTE local_420 [128];
  undefined4 local_1c;
  
  local_420[0].palVersion = 0x300;
  local_420[0].palNumEntries = *(WORD *)(in_EAX + 0x2c);
  uVar4 = 0;
  if (*(int *)(in_EAX + 0x2c) != 0) {
    iVar1 = 0;
    iVar3 = in_EAX;
    do {
      (&local_420[0].palPalEntry[0].peRed)[iVar1] = *(BYTE *)(iVar3 + 0x3e);
      (&local_420[0].palPalEntry[0].peBlue)[iVar1] = *(BYTE *)(iVar3 + 0x3c);
      (&local_420[0].palPalEntry[0].peGreen)[iVar1] = *(BYTE *)(iVar3 + 0x3d);
      if ((uVar4 < *(uint *)(in_EAX + 0x34)) || (*(uint *)(in_EAX + 0x38) <= uVar4)) {
        local_1c = 0;
      }
      else {
        local_1c = 4;
      }
      iVar3 = iVar3 + 4;
      (&local_420[0].palPalEntry[0].peFlags)[iVar1] = (BYTE)local_1c;
      uVar4 = uVar4 + 1;
      iVar1 = iVar1 + 4;
    } while (uVar4 < *(uint *)(in_EAX + 0x2c));
  }
  pHVar2 = CreatePalette(local_420);
  *(HPALETTE *)(in_EAX + 0x458) = pHVar2;
  if (*(int *)(in_EAX + 8) == 4) {
    (*DAT_00410454)(*(undefined4 *)(in_EAX + 0x45c),0,*(undefined4 *)(in_EAX + 0x2c),in_EAX + 0x3c);
  }
  return;
}

