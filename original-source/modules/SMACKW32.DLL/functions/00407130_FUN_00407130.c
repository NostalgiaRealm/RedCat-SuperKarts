/*
 * FUN_00407130 at 00407130
 * undefined __fastcall FUN_00407130(undefined4 param_1, uint param_2)
 * Address ranges: 00407130-0040721a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00407130(undefined4 param_1,uint param_2)

{
  undefined1 uVar1;
  int *dwUser;
  int iVar2;
  undefined4 *in_EAX;
  DWORD DVar3;
  uint uVar4;
  uint uVar5;
  DWORD_PTR *unaff_EBX;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_18;
  uint local_14;
  
  local_18 = in_EAX;
  local_14 = param_2;
  do {
    dwUser = (int *)*unaff_EBX;
    if (dwUser == (int *)0x0) break;
    uVar5 = dwUser[1] - dwUser[7];
    if (local_14 < (uint)(dwUser[1] - dwUser[7])) {
      uVar5 = local_14;
    }
    puVar6 = (undefined4 *)(*dwUser + dwUser[7]);
    puVar7 = local_18;
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    iVar2 = dwUser[7];
    local_18 = (undefined4 *)((int)local_18 + uVar5);
    local_14 = local_14 - uVar5;
    dwUser[7] = iVar2 + uVar5;
    if (iVar2 + uVar5 < (uint)dwUser[1]) break;
    *unaff_EBX = dwUser[6];
    DVar3 = timeGetTime();
    if ((int)(dwUser[2] - DVar3) < 1) {
      *(byte *)(dwUser + 4) = *(byte *)(dwUser + 4) | 1;
    }
    else {
      timeSetEvent(dwUser[2] - DVar3,0,donemarker,(DWORD_PTR)dwUser,0);
    }
  } while (local_14 != 0);
  if (local_14 != 0) {
    uVar1 = *(undefined1 *)((int)unaff_EBX + 0x2a);
    for (uVar5 = local_14 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *local_18 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
      local_18 = local_18 + 1;
    }
    for (uVar5 = local_14 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)local_18 = uVar1;
      local_18 = (undefined4 *)((int)local_18 + 1);
    }
    unaff_EBX[7] = unaff_EBX[7] + local_14;
  }
  return;
}

