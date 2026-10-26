/*
 * FUN_0046fcc4 at 0046fcc4
 * undefined __register FUN_0046fcc4(int param_1, undefined4 param_2)
 * Address ranges: 0046fcc4-0046fcf9;0046fd12-0046fd95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046fcc4(int param_1,undefined4 param_2)

{
  byte bVar1;
  uint uVar3;
  byte unaff_BL;
  uint uVar2;
  
  bVar1 = FUN_004581c8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x94),
                       CONCAT31((int3)((uint)param_2 >> 8),*(undefined1 *)(param_1 + 0x338)));
  uVar2 = (uint)bVar1;
  uVar3 = (uint)*(byte *)(param_1 + 0x338);
  switch(*(byte *)(param_1 + 0x338)) {
  case 0:
    unaff_BL = (&DAT_0047c4b4)[(uVar2 & 0x7f) + (uVar3 & 0x7f) * 2];
    break;
  case 1:
    unaff_BL = (&DAT_0047c4b4)[(uVar2 & 0x7f) + (uVar3 & 0x7f) * 2];
    break;
  case 2:
    unaff_BL = (&DAT_0047c4b4)[(uVar2 & 0x7f) + (uVar3 & 0x7f) * 2];
    break;
  case 3:
    unaff_BL = (&DAT_0047c4b4)[(uVar2 & 0x7f) + (uVar3 & 0x7f) * 2];
    break;
  case 4:
    unaff_BL = (&DAT_0047c4b4)[(uVar2 & 0x7f) + (uVar3 & 0x7f) * 2];
    break;
  case 5:
    unaff_BL = (&DAT_0047c4b4)[(uVar2 & 0x7f) + (uVar3 & 0x7f) * 2];
  }
  FUN_0045c5cc(*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22),unaff_BL);
  return;
}

