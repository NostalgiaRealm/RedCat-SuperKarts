/*
 * FUN_004059b0 at 004059b0
 * uint __fastcall FUN_004059b0(undefined4 param_1, undefined4 * param_2)
 * Address ranges: 004059b0-00405c55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_004059b0(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int in_EAX;
  DWORD DVar2;
  uint uVar3;
  uint unaff_EBX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  DWORD local_28;
  uint local_24;
  DWORD local_20;
  uint local_1c;
  undefined4 *local_18;
  
  local_1c = 0;
  local_28 = 0;
  local_18 = param_2;
  local_20 = timeGetTime();
  if (*(int *)(in_EAX + 0x42c) == 0) {
    ReadFile(*(HANDLE *)(in_EAX + 0x394),local_18,unaff_EBX,&local_28,(LPOVERLAPPED)0x0);
    local_1c = local_28;
LAB_00405bef:
    *(DWORD *)(in_EAX + 0x448) = *(int *)(in_EAX + 0x448) + local_28;
    if (*(uint *)(in_EAX + 0x4a0) == 0) {
      DVar2 = timeGetTime();
    }
    else {
      local_28 = local_20 +
                 (int)(((ulonglong)local_28 * 1000) / (ulonglong)*(uint *)(in_EAX + 0x4a0));
      do {
        DVar2 = timeGetTime();
      } while (DVar2 < local_28);
    }
    *(DWORD *)(in_EAX + 0x44c) = *(int *)(in_EAX + 0x44c) + (DVar2 - local_20);
    return local_1c;
  }
LAB_00405a05:
  iVar1 = DAT_0040e83c;
  if (*(int *)(in_EAX + 0x43c) != 0) goto code_r0x00405a12;
  goto LAB_00405af9;
code_r0x00405a12:
  local_24 = *(int *)(in_EAX + 0x430) - *(int *)(in_EAX + 0x434);
  if (unaff_EBX < local_24) {
    local_24 = unaff_EBX;
  }
  if (*(uint *)(in_EAX + 0x43c) < local_24) {
    local_24 = *(uint *)(in_EAX + 0x43c);
  }
  puVar4 = *(undefined4 **)(in_EAX + 0x434);
  puVar5 = local_18;
  for (uVar3 = local_24 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  for (uVar3 = local_24 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  *(int *)(in_EAX + 0x43c) = *(int *)(in_EAX + 0x43c) - local_24;
  *(uint *)(in_EAX + 0x444) = *(int *)(in_EAX + 0x444) + local_24;
  uVar3 = *(int *)(in_EAX + 0x434) + local_24;
  *(uint *)(in_EAX + 0x434) = uVar3;
  if (*(uint *)(in_EAX + 0x430) <= uVar3) {
    *(int *)(in_EAX + 0x434) = *(int *)(in_EAX + 0x42c);
    *(int *)(in_EAX + 0x430) = *(int *)(in_EAX + 0x42c) + *(int *)(in_EAX + 0x440);
    if (*(int *)(in_EAX + 0x43c) == 0) {
      *(undefined4 *)(in_EAX + 0x438) = *(undefined4 *)(in_EAX + 0x434);
    }
  }
  local_1c = local_1c + local_24;
  unaff_EBX = unaff_EBX - local_24;
  local_18 = (undefined4 *)((int)local_18 + local_24);
  iVar1 = DAT_0040e83c;
  if (unaff_EBX == 0) {
LAB_00405af9:
    while( true ) {
      if (iVar1 != 0) {
        (*DAT_00410474)();
      }
      uVar3 = local_1c;
      if (unaff_EBX < 0x1001) break;
      if (unaff_EBX < 0x4001) {
        local_24 = unaff_EBX & 0xfffff000;
      }
      else {
        local_24 = 0x4000;
      }
      ReadFile(*(HANDLE *)(in_EAX + 0x394),local_18,local_24,&local_24,(LPOVERLAPPED)0x0);
      iVar1 = DAT_0040e83c;
      unaff_EBX = unaff_EBX - local_24;
      local_18 = (undefined4 *)((int)local_18 + local_24);
      local_1c = uVar3 + local_24;
      local_28 = local_28 + local_24;
      *(uint *)(in_EAX + 0x444) = *(int *)(in_EAX + 0x444) + local_24;
    }
    if (unaff_EBX != 0) {
      local_24 = unaff_EBX + 0xfff & 0xfffff000;
      ReadFile(*(HANDLE *)(in_EAX + 0x394),*(LPVOID *)(in_EAX + 0x42c),local_24,&local_24,
               (LPOVERLAPPED)0x0);
      local_28 = local_28 + local_24;
      *(int *)(in_EAX + 0x434) = *(int *)(in_EAX + 0x42c);
      *(uint *)(in_EAX + 0x438) = local_24 + *(int *)(in_EAX + 0x42c);
      *(uint *)(in_EAX + 0x43c) = local_24;
      goto LAB_00405a05;
    }
    goto LAB_00405bef;
  }
  goto LAB_00405a05;
}

