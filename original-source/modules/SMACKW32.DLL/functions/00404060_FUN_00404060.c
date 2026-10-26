/*
 * FUN_00404060 at 00404060
 * undefined __stdcall FUN_00404060(void)
 * Address ranges: 00404060-00404174
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404060(void)

{
  int iVar1;
  int in_EAX;
  DWORD DVar2;
  uint uVar3;
  
  DVar2 = 0xffffffff;
  if (*(int *)(in_EAX + 0x460) != 0) {
    DVar2 = timeGetTime();
    uVar3 = DVar2 - *(int *)(in_EAX + 0x460);
    *(undefined4 *)(in_EAX + 0x460) = 0;
    if (*(uint *)(in_EAX + 0x488) < uVar3) {
      if (*(int *)(in_EAX + 0x490) != *(int *)(in_EAX + 0x370)) {
        *(undefined4 *)(in_EAX + 0x48c) = *(undefined4 *)(in_EAX + 0x488);
        *(undefined4 *)(in_EAX + 0x494) = *(undefined4 *)(in_EAX + 0x490);
        *(undefined4 *)(in_EAX + 0x490) = *(undefined4 *)(in_EAX + 0x370);
      }
      *(uint *)(in_EAX + 0x488) = uVar3;
    }
    else if ((*(uint *)(in_EAX + 0x48c) < uVar3) &&
            (*(int *)(in_EAX + 0x490) != *(int *)(in_EAX + 0x370))) {
      *(uint *)(in_EAX + 0x48c) = uVar3;
      *(undefined4 *)(in_EAX + 0x494) = *(undefined4 *)(in_EAX + 0x370);
    }
  }
  if (*(int *)(in_EAX + 0x468) != 0) {
    if (DVar2 == 0xffffffff) {
      DVar2 = timeGetTime();
    }
    iVar1 = *(int *)(in_EAX + 0x468);
    *(undefined4 *)(in_EAX + 0x468) = 0;
    *(DWORD *)(in_EAX + 0x480) = *(int *)(in_EAX + 0x480) + (DVar2 - iVar1);
  }
  if (*(int *)(in_EAX + 0x464) != 0) {
    if (DVar2 == 0xffffffff) {
      DVar2 = timeGetTime();
    }
    iVar1 = *(int *)(in_EAX + 0x464);
    *(undefined4 *)(in_EAX + 0x464) = 0;
    *(DWORD *)(in_EAX + 0x484) = *(int *)(in_EAX + 0x484) + (DVar2 - iVar1);
  }
  return;
}

