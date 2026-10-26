/*
 * FUN_00405c60 at 00405c60
 * undefined8 __fastcall FUN_00405c60(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00405c60-00405d62
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined8 __fastcall FUN_00405c60(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  int in_EAX;
  DWORD DVar2;
  DWORD DVar3;
  uint uVar4;
  DWORD local_1c;
  
  local_1c = 0;
  if ((*(uint *)(in_EAX + 0x370) < *(uint *)(in_EAX + 0xc)) &&
     (0xfff < *(int *)(in_EAX + 0x440) - *(int *)(in_EAX + 0x43c))) {
    DVar2 = timeGetTime();
    ReadFile(*(HANDLE *)(in_EAX + 0x394),*(LPVOID *)(in_EAX + 0x438),0x1000,&local_1c,
             (LPOVERLAPPED)0x0);
    *(int *)(in_EAX + 0x43c) = *(int *)(in_EAX + 0x43c) + local_1c;
    uVar4 = *(int *)(in_EAX + 0x438) + local_1c;
    *(uint *)(in_EAX + 0x438) = uVar4;
    if (*(uint *)(in_EAX + 0x430) < uVar4) {
      *(uint *)(in_EAX + 0x430) = uVar4;
      *(undefined4 *)(in_EAX + 0x438) = *(undefined4 *)(in_EAX + 0x42c);
    }
    if (*(uint *)(in_EAX + 0x458) < *(uint *)(in_EAX + 0x43c)) {
      *(uint *)(in_EAX + 0x458) = *(uint *)(in_EAX + 0x43c);
    }
    uVar4 = *(uint *)(in_EAX + 0x4a0);
    *(DWORD *)(in_EAX + 0x450) = *(int *)(in_EAX + 0x450) + local_1c;
    if (uVar4 == 0) {
      DVar3 = timeGetTime();
    }
    else {
      uVar1 = (ulonglong)local_1c;
      do {
        DVar3 = timeGetTime();
      } while (DVar3 < DVar2 + (int)((uVar1 * 1000) / (ulonglong)uVar4));
    }
    *(DWORD *)(in_EAX + 0x454) = *(int *)(in_EAX + 0x454) + (DVar3 - DVar2);
  }
  return CONCAT44(param_2,local_1c);
}

