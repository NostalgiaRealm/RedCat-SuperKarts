/*
 * FUN_00406a20 at 00406a20
 * ulonglong __fastcall FUN_00406a20(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00406a20-00406bbe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

ulonglong __fastcall FUN_00406a20(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  undefined1 uVar2;
  int in_EAX;
  uint uVar3;
  DWORD DVar4;
  DWORD DVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 extraout_ECX;
  undefined4 *puVar9;
  
  uVar3 = FUN_00406e30(0,0xffffffff,(byte)*(undefined4 *)(in_EAX + 0x68));
  if (uVar3 == 0) {
    puVar9 = *(undefined4 **)(in_EAX + 0x54);
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar9 = 0;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    puVar9 = *(undefined4 **)(in_EAX + 0x58);
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = 0;
      puVar9 = puVar9 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar9 = 0;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    **(int **)(in_EAX + 0x54) = *(int *)(in_EAX + 0x54) + 0x20;
    **(int **)(in_EAX + 0x58) = *(int *)(in_EAX + 0x58) + 0x20;
    uVar6 = *(undefined4 *)(in_EAX + 0x3c);
    *(undefined4 *)(*(int *)(in_EAX + 0x54) + 4) = uVar6;
    *(undefined4 *)(*(int *)(in_EAX + 0x58) + 4) = uVar6;
    *(undefined4 *)(*(int *)(in_EAX + 0x54) + 0x10) = 1;
    *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x10) = 1;
    pbVar1 = (byte *)(*(int *)(in_EAX + 0x58) + 0x10);
    *pbVar1 = *pbVar1 | 1;
    *(undefined4 *)(*(int *)(in_EAX + 0x54) + 4) = 4;
    uVar3 = *(uint *)(in_EAX + 0x3c);
    if (*(int *)(in_EAX + 0x48) == 0) {
      uVar2 = 0x80;
    }
    else {
      uVar2 = 0;
    }
    puVar9 = (undefined4 *)(*(int *)(in_EAX + 0x54) + 0x20);
    for (uVar8 = uVar3 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar9 = CONCAT22(CONCAT11(uVar2,uVar2),CONCAT11(uVar2,uVar2));
      puVar9 = puVar9 + 1;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar9 = uVar2;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    FUN_00406d50(0,*(int *)(in_EAX + 0x54));
    DVar4 = timeGetTime();
    do {
      DVar5 = timeGetTime();
      if (DVar4 + 1000 <= DVar5) {
        pbVar1 = (byte *)(*(int *)(in_EAX + 0x54) + 0x10);
        *pbVar1 = *pbVar1 | 1;
        uVar6 = FUN_00406bc0(extraout_ECX);
        return CONCAT44(param_2,uVar6) & 0xffffffffffffff00;
      }
    } while ((*(byte *)(*(int *)(in_EAX + 0x54) + 0x10) & 1) == 0);
    uVar3 = CONCAT31((int3)((uint)*(int *)(in_EAX + 0x54) >> 8),1);
  }
  else {
    uVar3 = uVar3 & 0xffffff00;
  }
  return CONCAT44(param_2,uVar3);
}

