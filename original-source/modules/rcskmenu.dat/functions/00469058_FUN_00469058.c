/*
 * FUN_00469058 at 00469058
 * undefined __register FUN_00469058(int * param_1, char * param_2, undefined4 * param_3, undefined4 param_4, uint * param_5)
 * Address ranges: 00469058-00469320
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00469058(int *param_1,char *param_2,undefined4 *param_3,int param_4,uint *param_5)

{
  uint *puVar1;
  int *piVar2;
  byte bVar3;
  BSTR pOVar4;
  DWORD DVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_678;
  undefined1 *puStack_674;
  undefined1 *puStack_670;
  undefined4 uStack_66c;
  undefined1 *puStack_668;
  undefined1 *puStack_664;
  uint local_654 [256];
  uint auStack_254 [128];
  undefined1 local_54 [32];
  uint *local_34;
  undefined4 *local_30;
  uint local_2c;
  uint local_28;
  uint *local_24;
  uint *local_20;
  uint *local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  undefined4 *local_c;
  int *local_8;
  uint *puVar9;
  
  puStack_664 = (undefined1 *)0x46907a;
  local_c = param_3;
  local_8 = param_1;
  FUN_00404300((int)local_54,(int)&DAT_0040ce14);
  puStack_668 = &LAB_00469344;
  uStack_66c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_66c;
  local_18 = 0;
  puStack_674 = &LAB_00469321;
  uStack_678 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_678;
  local_14 = (uint)(byte)param_2[1];
  puStack_670 = &stack0xfffffffc;
  puStack_664 = &stack0xfffffffc;
  if (local_14 != 0) {
    local_1c = param_5;
    uVar6 = 0;
    puVar8 = local_654 + local_14 * 4;
    puStack_670 = &stack0xfffffffc;
    puStack_664 = &stack0xfffffffc;
    do {
      puVar1 = local_1c;
      puVar9 = puVar8 + -4;
      local_10 = (uint)(param_2[uVar6 + 3] & 0x7f);
      bVar3 = param_2[uVar6 + 3] & 0x80;
      if (local_10 == 10) {
        *puVar9 = 10;
        puVar8[-2] = 0x80020004;
      }
      else {
        if (local_10 == 0x48) {
          local_20 = auStack_254 + local_18 * 2;
          if (bVar3 == 0) {
            pOVar4 = FUN_004047d0((LPCSTR)*local_1c);
            *local_20 = (uint)pOVar4;
            local_20[1] = 0;
            *puVar9 = 8;
            puVar8[-2] = *local_20;
          }
          else {
            pOVar4 = FUN_004047d0(*(LPCSTR *)*local_1c);
            *local_20 = (uint)pOVar4;
            local_20[1] = *local_1c;
            *puVar9 = 0x4008;
            puVar8[-2] = (uint)local_20;
          }
          local_18 = local_18 + 1;
        }
        else if (bVar3 == 0) {
          if (local_10 == 0xc) {
            if ((short)*local_1c == 0x100) {
              local_24 = auStack_254 + local_18 * 2;
              pOVar4 = FUN_004047d0(*(LPCSTR *)(*local_1c + 8));
              *local_24 = (uint)pOVar4;
              local_24[1] = 0;
              *puVar9 = 8;
              puVar8[-2] = *local_24;
              local_18 = local_18 + 1;
            }
            else {
              *puVar9 = *local_1c;
              puVar8[-3] = puVar1[1];
              puVar8[-2] = puVar1[2];
              puVar8[-1] = puVar1[3];
              local_1c = local_1c + 3;
            }
          }
          else {
            *puVar9 = local_10;
            puVar8[-2] = *local_1c;
            if ((4 < (int)local_10) && ((int)local_10 < 8)) {
              local_1c = local_1c + 1;
              puVar8[-1] = *local_1c;
            }
          }
        }
        else {
          if ((local_10 == 0xc) && (*(short *)*local_1c == 0x100)) {
            FUN_00404ac4((VARIANT *)*local_1c,(VARIANTARG *)*local_1c,8);
          }
          *puVar9 = local_10 | 0x4000;
          puVar8[-2] = *local_1c;
        }
        local_1c = local_1c + 1;
      }
      uVar6 = uVar6 + 1;
      puVar8 = puVar9;
    } while (uVar6 != local_14);
  }
  piVar2 = local_8;
  local_34 = local_654;
  local_30 = local_c + 1;
  local_2c = local_14;
  local_28 = (uint)(byte)param_2[2];
  if (*param_2 == '\x04') {
    *local_c = 0xfffffffd;
    local_30 = local_c;
    local_28 = local_28 + 1;
  }
  DVar5 = (**(code **)(*local_8 + 0x18))();
  iVar7 = local_18;
  if (DVar5 != 0) {
    FUN_004695d4(DVar5,(int)local_54);
    iVar7 = local_18;
  }
  while (iVar7 != 0) {
    iVar7 = iVar7 + -1;
    if ((int *)auStack_254[iVar7 * 2 + 1] != (int *)0x0) {
      FUN_004047ac((LPCWSTR)auStack_254[iVar7 * 2],(int *)auStack_254[iVar7 * 2 + 1]);
    }
  }
  *in_FS_OFFSET = piVar2;
  iVar7 = local_18;
  while (iVar7 != 0) {
    iVar7 = iVar7 + -1;
    SysFreeString((BSTR)auStack_254[iVar7 * 2]);
  }
  return;
}

