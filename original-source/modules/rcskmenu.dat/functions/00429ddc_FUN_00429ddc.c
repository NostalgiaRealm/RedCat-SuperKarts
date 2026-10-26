/*
 * FUN_00429ddc at 00429ddc
 * uint __register FUN_00429ddc(uint param_1, int param_2)
 * Address ranges: 00429ddc-00429fac;00429fcd-0042a0d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00429ddc(uint param_1,int param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_14;
  uint local_10;
  
  if ((*(char *)(param_1 + 0x1f) == '\0') || (3 < *(ushort *)(param_2 + 4))) {
    uVar3 = (int)*(short *)(param_2 + 4);
    switch((int)*(short *)(param_2 + 4)) {
    case 0:
      uVar3 = FUN_0042a14c(param_1,*(int *)(param_1 + 0xc) - (uint)*(ushort *)(param_1 + 8));
      break;
    case 1:
      uVar3 = FUN_0042a14c(param_1,*(int *)(param_1 + 0xc) + (uint)*(ushort *)(param_1 + 8));
      break;
    case 2:
      iVar6 = FUN_00429ce4(param_1);
      uVar3 = FUN_0042a14c(param_1,*(int *)(param_1 + 0xc) - iVar6);
      break;
    case 3:
      iVar6 = FUN_00429ce4(param_1);
      uVar3 = FUN_0042a14c(param_1,iVar6 + *(int *)(param_1 + 0xc));
      break;
    case 4:
      if (*(int *)(param_1 + 0x14) < 0x8000) {
        uVar3 = FUN_0042a14c(param_1,(int)*(short *)(param_2 + 6));
      }
      else {
        iVar6 = FUN_00429d7c();
        uVar3 = FUN_0042a14c(param_1,iVar6);
      }
      break;
    case 5:
      uVar3 = param_1;
      if (*(char *)(param_1 + 0x1d) != '\0') {
        if (*(int *)(param_1 + 0x14) < 0x8000) {
          uVar3 = FUN_0042a14c(param_1,(int)*(short *)(param_2 + 6));
        }
        else {
          iVar6 = FUN_00429d7c();
          uVar3 = FUN_0042a14c(param_1,iVar6);
        }
      }
      break;
    case 6:
      uVar3 = FUN_0042a14c(param_1,0);
      break;
    case 7:
      uVar3 = FUN_0042a14c(param_1,*(int *)(param_1 + 0x14));
    }
  }
  else {
    if (*(ushort *)(param_2 + 4) < 2) {
      uVar5 = (uint)*(ushort *)(param_1 + 8);
      iVar6 = *(int *)(param_1 + 0x40);
      local_10 = (uint)((longlong)(ulonglong)uVar5 / (longlong)iVar6);
      uVar3 = (uint)((longlong)(ulonglong)uVar5 / (longlong)iVar6);
      local_14 = (int)((longlong)(ulonglong)uVar5 % (longlong)iVar6);
    }
    else if ((ushort)(*(ushort *)(param_2 + 4) - 2) < 2) {
      iVar6 = *(int *)(param_1 + 0x3c);
      local_14 = (int)(uint)*(ushort *)(param_1 + 10) % iVar6;
      uVar3 = (int)(uint)*(ushort *)(param_1 + 10) / iVar6;
      local_10 = uVar3;
    }
    else {
      iVar6 = 0;
      local_10 = 0;
      uVar3 = 0;
      local_14 = 0;
    }
    iVar2 = 0;
    for (; 0 < iVar6; iVar6 = iVar6 + -1) {
      iVar4 = FUN_00406bc8();
      if (iVar4 - iVar2 < *(int *)(param_1 + 0x20)) {
        Sleep(*(int *)(param_1 + 0x20) - (iVar4 - iVar2));
      }
      sVar1 = *(short *)(param_2 + 4);
      if (sVar1 == 0) {
        FUN_0042a14c(param_1,*(int *)(param_1 + 0xc) - local_10);
      }
      else if (sVar1 == 1) {
        FUN_0042a14c(param_1,*(int *)(param_1 + 0xc) + local_10);
      }
      else if (sVar1 == 2) {
        FUN_0042a14c(param_1,*(int *)(param_1 + 0xc) - local_10);
      }
      else if (sVar1 == 3) {
        FUN_0042a14c(param_1,*(int *)(param_1 + 0xc) + local_10);
      }
      uVar3 = (**(code **)(**(int **)(param_1 + 4) + 0x80))();
      iVar2 = iVar4;
    }
    if (0 < local_14) {
      sVar1 = *(short *)(param_2 + 4);
      if (sVar1 == 0) {
        uVar3 = FUN_0042a14c(param_1,*(int *)(param_1 + 0xc) - local_14);
      }
      else if (sVar1 == 1) {
        uVar3 = FUN_0042a14c(param_1,*(int *)(param_1 + 0xc) + local_14);
      }
      else if (sVar1 == 2) {
        uVar3 = FUN_0042a14c(param_1,*(int *)(param_1 + 0xc) - local_14);
      }
      else {
        uVar3 = CONCAT22((short)((uint)param_2 >> 0x10),sVar1 + -3);
        if ((short)(sVar1 + -3) == 0) {
          uVar3 = FUN_0042a14c(param_1,*(int *)(param_1 + 0xc) + local_14);
        }
      }
    }
  }
  return uVar3;
}

