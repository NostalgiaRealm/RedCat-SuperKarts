/*
 * FUN_0046c1e0 at 0046c1e0
 * undefined FUN_0046c1e0(void)
 * Address ranges: 0046c1e0-0046c507
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0046c1e0(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(int *)(param_1 + 8) != 1) {
    piVar8 = (int *)FUN_0046c510();
    (**(code **)(*piVar8 + 0x50))(param_2);
    FUN_0046c670(*(undefined4 *)(param_2 + 0x10));
    *(float *)(param_1 + 0x68) = (float)*(int *)(param_2 + 0x18);
    FUN_0046c860(*(undefined4 *)(param_2 + 0x14));
    FUN_0046c890(0);
    return;
  }
  if (*(int *)(param_1 + 0x60) == 0) {
LAB_0046c35c:
    pvVar3 = operator_new(0xff8);
    if (*(int *)(param_1 + 0x60) == 0) {
      *(undefined4 *)(param_1 + 0x5c) = 2;
      pvVar6 = operator_new(8);
      *(void **)(param_1 + 0x58) = pvVar6;
      *(void **)((int)pvVar6 + 4) = pvVar3;
      FUN_0046d9c0((int)pvVar3 + 0x7fc,*(int *)(param_1 + 0x58) + 4);
      *(undefined4 *)(param_1 + 0x38) = local_10;
      *(undefined4 *)(param_1 + 0x3c) = local_c;
      *(undefined4 *)(param_1 + 0x40) = local_8;
      *(undefined4 *)(param_1 + 0x44) = local_4;
      *(undefined4 *)(param_1 + 0x48) = local_10;
      *(undefined4 *)(param_1 + 0x4c) = local_c;
      *(undefined4 *)(param_1 + 0x50) = local_8;
      *(undefined4 *)(param_1 + 0x54) = local_4;
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x54);
      if (uVar2 < (uint)(*(int *)(param_1 + 0x58) + -4 + *(int *)(param_1 + 0x5c) * 4)) {
        *(undefined4 **)(param_1 + 0x54) = (undefined4 *)(uVar2 + 4);
        *(undefined4 *)(uVar2 + 4) = pvVar3;
        FUN_0046d9c0(pvVar3,*(undefined4 *)(param_1 + 0x54));
        *(undefined4 *)(param_1 + 0x48) = local_10;
        *(undefined4 *)(param_1 + 0x4c) = local_c;
        *(undefined4 *)(param_1 + 0x50) = local_8;
        *(undefined4 *)(param_1 + 0x54) = local_4;
      }
      else {
        iVar4 = ((int)(uVar2 - *(int *)(param_1 + 0x44)) >> 2) + 1;
        iVar5 = FUN_0043acf0(iVar4 * 2);
        piVar8 = (int *)(iVar5 + iVar4 * 4);
        *piVar8 = (int)pvVar3;
        FUN_0046d9c0(*(undefined4 *)(param_1 + 0x40),iVar5);
        *(undefined4 *)(param_1 + 0x38) = local_10;
        *(undefined4 *)(param_1 + 0x3c) = local_c;
        *(undefined4 *)(param_1 + 0x40) = local_8;
        *(undefined4 *)(param_1 + 0x44) = local_4;
        iVar4 = *piVar8;
        *(int *)(param_1 + 0x48) = iVar4;
        *(int *)(param_1 + 0x4c) = iVar4 + 0xff8;
        *(void **)(param_1 + 0x50) = pvVar3;
        *(int **)(param_1 + 0x54) = piVar8;
      }
    }
    iVar4 = *(int *)(param_1 + 0x50);
    *(int *)(param_1 + 0x50) = iVar4 + 0x1c;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x50);
    if (iVar4 == *(int *)(param_1 + 0x4c)) goto LAB_0046c35c;
    *(int *)(param_1 + 0x50) = iVar4 + 0x1c;
    if (iVar4 + 0x1c == *(int *)(param_1 + 0x4c)) {
      FUN_0046d9f0(iVar4,param_2);
      pvVar3 = operator_new(0xff8);
      if (*(int *)(param_1 + 0x60) == 0) {
        *(undefined4 *)(param_1 + 0x5c) = 2;
        FUN_0046d9a0();
        *(void **)(*(int *)(param_1 + 0x58) + 4) = pvVar3;
        FUN_0046d9c0((int)pvVar3 + 0x7fc,*(int *)(param_1 + 0x58) + 4);
        *(undefined4 *)(param_1 + 0x38) = local_10;
        *(undefined4 *)(param_1 + 0x3c) = local_c;
        *(undefined4 *)(param_1 + 0x40) = local_8;
        *(undefined4 *)(param_1 + 0x44) = local_4;
        *(undefined4 *)(param_1 + 0x48) = local_10;
        *(undefined4 *)(param_1 + 0x4c) = local_c;
        *(undefined4 *)(param_1 + 0x50) = local_8;
        *(undefined4 *)(param_1 + 0x54) = local_4;
      }
      else {
        uVar2 = *(uint *)(param_1 + 0x54);
        if (uVar2 < (uint)(*(int *)(param_1 + 0x58) + -4 + *(int *)(param_1 + 0x5c) * 4)) {
          *(undefined4 **)(param_1 + 0x54) = (undefined4 *)(uVar2 + 4);
          *(undefined4 *)(uVar2 + 4) = pvVar3;
          FUN_0046d9c0(pvVar3,*(undefined4 *)(param_1 + 0x54));
          *(undefined4 *)(param_1 + 0x48) = local_10;
          *(undefined4 *)(param_1 + 0x4c) = local_c;
          *(undefined4 *)(param_1 + 0x50) = local_8;
          *(undefined4 *)(param_1 + 0x54) = local_4;
        }
        else {
          iVar4 = ((int)(uVar2 - *(int *)(param_1 + 0x44)) >> 2) + 1;
          iVar5 = FUN_0043acf0(iVar4 * 2);
          puVar1 = (undefined4 *)(iVar5 + iVar4 * 4);
          *puVar1 = pvVar3;
          FUN_0046d9c0(*(undefined4 *)(param_1 + 0x40),iVar5);
          *(undefined4 *)(param_1 + 0x38) = local_10;
          *(undefined4 *)(param_1 + 0x3c) = local_c;
          *(undefined4 *)(param_1 + 0x40) = local_8;
          *(undefined4 *)(param_1 + 0x44) = local_4;
          FUN_0046d9c0(pvVar3,puVar1);
          *(undefined4 *)(param_1 + 0x48) = local_10;
          *(undefined4 *)(param_1 + 0x4c) = local_c;
          *(undefined4 *)(param_1 + 0x50) = local_8;
          *(undefined4 *)(param_1 + 0x54) = local_4;
        }
      }
      goto LAB_0046c491;
    }
  }
  FUN_0046d9f0(iVar4,param_2);
LAB_0046c491:
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
  if (0.1 < *(float *)(param_1 + 100)) {
    return;
  }
  uVar7 = __ftol();
  FUN_0046c860(uVar7);
  return;
}

