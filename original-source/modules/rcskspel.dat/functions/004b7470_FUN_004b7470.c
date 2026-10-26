/*
 * FUN_004b7470 at 004b7470
 * undefined FUN_004b7470(void)
 * Address ranges: 004b7470-004b7a1e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b7470(int param_1)

{
  short sVar1;
  short sVar2;
  int *piVar3;
  undefined2 uVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  HLOCAL pvVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined2 *puVar13;
  undefined2 *local_838;
  int iStack_834;
  undefined2 uStack_82e;
  int iStack_82c;
  short local_828;
  short local_826;
  short local_824;
  short local_822;
  undefined4 local_820;
  undefined4 local_81c;
  int local_818;
  short *local_814;
  uint uStack_810;
  undefined4 local_80c;
  uint uStack_808;
  uint uStack_804;
  short local_800 [1024];
  
  local_80c = FUN_004b7150();
  FUN_004afce0(s_Load_new_ascii_set__s__005010f4,param_1);
  iVar5 = FUN_004b96d0(param_1);
  if (iVar5 != 0) {
    psVar6 = local_800;
    for (iVar10 = 0x200; iVar10 != 0; iVar10 = iVar10 + -1) {
      psVar6[0] = 0;
      psVar6[1] = 0;
      psVar6 = psVar6 + 2;
    }
    FUN_004bf930(local_800,8,0x100,iVar5);
    psVar6 = local_800;
    iVar10 = -1;
    iVar12 = -1;
    iVar11 = 0;
    do {
      if (((0 < *psVar6) && (0 < psVar6[1])) &&
         (iVar7 = (int)psVar6[1] * (int)*psVar6, iVar7 - iVar10 != 0 && iVar10 <= iVar7)) {
        iVar10 = iVar7;
        iVar12 = iVar11;
      }
      iVar11 = iVar11 + 1;
      psVar6 = psVar6 + 4;
    } while (iVar11 < 0x100);
    if ((-1 < iVar10) && (-1 < iVar12)) {
      FUN_004afce0(s_Largest_buffer_size_of_character_005010b4,iVar10,iVar12);
      FUN_004bf930(&local_824,1,2,iVar5);
      FUN_004bf930(&local_822,1,2,iVar5);
      FUN_004bf930(&local_826,1,2,iVar5);
      FUN_004bf930(&local_828,1,2,iVar5);
      *(int *)(param_1 + 0x70) = (int)local_824;
      *(int *)(param_1 + 0x74) = (int)local_822;
      *(int *)(param_1 + 0x78) = (int)local_826;
      sVar1 = local_800[iVar12 * 4];
      sVar2 = local_800[iVar12 * 4 + 1];
      *(undefined4 *)(param_1 + 0x88) = 0;
      *(undefined4 *)(param_1 + 0x8c) = 0;
      *(undefined4 *)(param_1 + 0x6c) = 3;
      *(undefined4 *)(param_1 + 100) = 0x100;
      *(int *)(param_1 + 0x7c) = (int)local_828;
      *(int *)(param_1 + 0x80) = (int)sVar1;
      *(int *)(param_1 + 0x84) = (int)sVar2;
      pvVar8 = LocalAlloc(0x40,0xc00);
      *(HLOCAL *)(param_1 + 0x68) = pvVar8;
      if (pvVar8 == (HLOCAL)0x0) {
        return 2000;
      }
      iVar10 = 0;
      do {
        pvVar8 = LocalAlloc(0x40,0xc);
        *(HLOCAL *)(iVar10 + *(int *)(param_1 + 0x68)) = pvVar8;
        if (*(int *)(iVar10 + *(int *)(param_1 + 0x68)) == 0) {
          return 2000;
        }
        iVar10 = iVar10 + 0xc;
      } while (iVar10 < 0xc00);
      FUN_004b7160(param_1);
      FUN_004afce0(s_Importing_char_data_0050109c);
      local_814 = local_800 + 1;
      local_818 = 0;
      iVar10 = 0;
      do {
        iVar12 = local_818;
        iVar11 = 0;
        if ((local_814[-1] < 1) || (*local_814 < 1)) {
          *(undefined4 *)(*(int *)(DAT_006ab868 + 0x68) + 8 + iVar10) = 0;
          *(undefined4 *)(*(int *)(*(int *)(DAT_006ab868 + 0x68) + iVar10) + 4) = 0;
          *(undefined4 *)(*(int *)(*(int *)(DAT_006ab868 + 0x68) + iVar10) + 8) = 0;
        }
        else {
          *(int *)(*(int *)(*(int *)(DAT_006ab868 + 0x68) + iVar10) + 4) = (int)local_814[-1];
          *(int *)(*(int *)(*(int *)(DAT_006ab868 + 0x68) + iVar10) + 8) = (int)*local_814;
          *(undefined4 *)(*(int *)(DAT_006ab868 + 0x68) + 8 + iVar10) = 1;
          FUN_004b9570(iVar5,*(undefined4 *)(local_814 + 1),0);
          iVar7 = *(int *)(*(int *)(DAT_006ab868 + 0x68) + iVar10);
          uVar9 = FUN_004b0900(*(undefined4 *)(iVar7 + 4),*(undefined4 *)(iVar7 + 8));
          **(undefined4 **)(*(int *)(DAT_006ab868 + 0x68) + iVar10) = uVar9;
          if (**(int **)(*(int *)(DAT_006ab868 + 0x68) + iVar10) == 0) {
            return 2000;
          }
          uVar9 = DAT_004fead8;
          if (DAT_006ab82c != 0) {
            if (DAT_006ab82c == 4) {
              uVar9 = FUN_004b5740(DAT_006a6500,0x18);
            }
            else {
              uVar9 = FUN_004b5740(DAT_004fead8,8);
            }
          }
          piVar3 = (int *)**(undefined4 **)(*(int *)(DAT_006ab868 + 0x68) + iVar10);
          local_820 = uVar9;
          local_81c = uVar9;
          iVar7 = (**(code **)(*piVar3 + 0x74))(piVar3,8,&local_820);
          if (iVar7 != 0) {
            uVar9 = FUN_004b0190(iVar7);
            FUN_004afee0(s__s__d____failed_to_set_color_key_004ff660,
                         s_C__libraries_dxdraw_ascii_cpp_00500fac,0x423,uVar9);
          }
          local_838 = (undefined2 *)FUN_004b71b0(iVar12,&iStack_82c);
          switch(DAT_006ab82c) {
          case 0:
            iVar12 = *(int *)(*(int *)(DAT_006ab868 + 0x68) + iVar10);
            if (0 < *(int *)(iVar12 + 8)) {
              do {
                FUN_004bf930(local_838,1,*(undefined4 *)(iVar12 + 4),iVar5);
                local_838 = (undefined2 *)((int)local_838 + iStack_82c);
                iVar11 = iVar11 + 1;
                iVar12 = *(int *)(*(int *)(DAT_006ab868 + 0x68) + iVar10);
              } while (iVar11 < *(int *)(iVar12 + 8));
            }
            break;
          case 1:
            iStack_834 = 0;
            iVar12 = *(int *)(DAT_006ab868 + 0x68);
            iVar11 = DAT_006ab868;
            if (0 < *(int *)(*(int *)(iVar10 + iVar12) + 8)) {
              do {
                iVar7 = 0;
                puVar13 = local_838;
                if (0 < *(int *)(*(int *)(iVar10 + iVar12) + 4)) {
                  do {
                    FUN_004bf930(&uStack_808,1,1,iVar5);
                    uVar4 = FUN_004b5740(uStack_808 & 0xff,8);
                    *puVar13 = uVar4;
                    puVar13 = puVar13 + 1;
                    iVar7 = iVar7 + 1;
                    iVar11 = DAT_006ab868;
                  } while (iVar7 < *(int *)(*(int *)(*(int *)(DAT_006ab868 + 0x68) + iVar10) + 4));
                }
                local_838 = (undefined2 *)((int)local_838 + iStack_82c);
                iVar12 = *(int *)(iVar11 + 0x68);
                iStack_834 = iStack_834 + 1;
              } while (iStack_834 < *(int *)(*(int *)(iVar10 + iVar12) + 8));
            }
            break;
          case 2:
            iStack_834 = 0;
            iVar12 = *(int *)(DAT_006ab868 + 0x68);
            iVar11 = DAT_006ab868;
            if (0 < *(int *)(*(int *)(iVar10 + iVar12) + 8)) {
              do {
                iVar7 = 0;
                puVar13 = local_838;
                if (0 < *(int *)(*(int *)(iVar10 + iVar12) + 4)) {
                  do {
                    FUN_004bf930(&uStack_810,1,1,iVar5);
                    FUN_004b5910(uStack_810 & 0xff,8,puVar13);
                    puVar13 = (undefined2 *)((int)puVar13 + 3);
                    iVar7 = iVar7 + 1;
                    iVar11 = DAT_006ab868;
                  } while (iVar7 < *(int *)(*(int *)(*(int *)(DAT_006ab868 + 0x68) + iVar10) + 4));
                }
                local_838 = (undefined2 *)((int)local_838 + iStack_82c);
                iVar12 = *(int *)(iVar11 + 0x68);
                iStack_834 = iStack_834 + 1;
              } while (iStack_834 < *(int *)(*(int *)(iVar10 + iVar12) + 8));
            }
            break;
          case 4:
            iStack_834 = 0;
            iVar12 = *(int *)(DAT_006ab868 + 0x68);
            iVar11 = DAT_006ab868;
            if (0 < *(int *)(*(int *)(iVar10 + iVar12) + 8)) {
              do {
                iVar7 = 0;
                puVar13 = local_838;
                if (0 < *(int *)(*(int *)(iVar10 + iVar12) + 4)) {
                  do {
                    FUN_004bf930(&uStack_804,1,1,iVar5);
                    FUN_004bf930(&uStack_82e,1,1,iVar5);
                    FUN_004bf930((int)&uStack_82e + 1,1,1,iVar5);
                    uVar4 = FUN_004b5740((uint)uStack_82e << 8 | uStack_804 & 0xff,0x18);
                    *puVar13 = uVar4;
                    puVar13 = puVar13 + 1;
                    iVar7 = iVar7 + 1;
                    iVar11 = DAT_006ab868;
                  } while (iVar7 < *(int *)(*(int *)(*(int *)(DAT_006ab868 + 0x68) + iVar10) + 4));
                }
                local_838 = (undefined2 *)((int)local_838 + iStack_82c);
                iVar12 = *(int *)(iVar11 + 0x68);
                iStack_834 = iStack_834 + 1;
              } while (iStack_834 < *(int *)(*(int *)(iVar10 + iVar12) + 8));
            }
          }
          iVar12 = local_818;
          FUN_004b7270(local_818,local_838);
          if ((*(byte *)(iVar5 + 0xc) & 0x20) != 0) {
            return 0x3e9;
          }
        }
        iVar10 = iVar10 + 0xc;
        local_818 = iVar12 + 1;
        local_814 = local_814 + 4;
        if (0xbff < iVar10) {
          *(undefined4 *)(DAT_006ab868 + 0x90) = 0x457;
          FUN_004b7160(local_80c);
          return 0;
        }
      } while( true );
    }
  }
  return 1000;
}

