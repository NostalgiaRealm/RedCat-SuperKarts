/*
 * FUN_0044d4d0 at 0044d4d0
 * undefined FUN_0044d4d0(void)
 * Address ranges: 0044d4d0-0044d704
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_0044d4d0(int param_1,undefined4 param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  uint local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cd9ed;
  local_c = ExceptionList;
  local_4 = 0;
  local_18 = 0;
  ExceptionList = &local_c;
  do {
    if ((*(int *)(param_1 + 4) == 0) ||
       ((uint)((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x70) <= local_18)) {
      FUN_004afee0(s___s___Objectname___s__not_found_a_004f0a08,
                   s_D__work_rcsk_Code_game_msh_Main__004f09e4,FUN_0044da80,0xb3);
      if (param_3 != (byte *)0x0) {
        bVar1 = param_3[-1];
        if ((bVar1 == 0) || (bVar1 == 0xff)) {
          FUN_004bc150(param_3 + -1);
        }
        else {
          param_3[-1] = bVar1 - 1;
        }
      }
      ExceptionList = local_c;
      return 0xffffffff;
    }
    uVar7 = 0;
    if (param_4 != 0) {
      do {
        if (param_3 == (byte *)0x0) {
          pbVar5 = &DAT_004d2404;
        }
        else {
          FUN_0044da90();
          pbVar5 = param_3 + uVar7;
        }
        if ('`' < (char)*pbVar5) {
          if ((param_4 < uVar7) || (param_3 == (byte *)0x0)) {
            pbVar5 = &DAT_004d2404;
          }
          else {
            FUN_0044da90();
            pbVar5 = param_3 + uVar7;
          }
          if ((char)*pbVar5 < '{') {
            if ((param_4 < uVar7) || (param_3 == (byte *)0x0)) {
              pbVar5 = &DAT_004d2404;
            }
            else {
              FUN_0044da90();
              pbVar5 = param_3 + uVar7;
            }
            if ((param_4 < uVar7) || (param_3 == (byte *)0x0)) {
              pbVar2 = &DAT_004d2404;
            }
            else {
              FUN_0044da90();
              pbVar2 = param_3 + uVar7;
            }
            *pbVar2 = *pbVar5 - 0x20;
          }
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < param_4);
    }
    iVar3 = FUN_0044f530();
    puVar4 = *(undefined1 **)(iVar3 + 4);
    if (puVar4 == (undefined1 *)0x0) {
      puVar4 = &DAT_004d2404;
    }
    FUN_004afce0(s_NAME___s__004f09d8,puVar4);
    iVar3 = FUN_0044f530();
    uVar7 = *(uint *)(iVar3 + 8);
    pbVar5 = *(byte **)(iVar3 + 4);
    if (pbVar5 == (byte *)0x0) {
      pbVar5 = &DAT_004d2404;
    }
    uVar6 = param_4;
    if (uVar7 <= param_4) {
      uVar6 = uVar7;
    }
    bVar8 = false;
    iVar3 = 0;
    bVar9 = true;
    pbVar2 = param_3;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      bVar8 = *pbVar2 < *pbVar5;
      bVar9 = *pbVar2 == *pbVar5;
      pbVar2 = pbVar2 + 1;
      pbVar5 = pbVar5 + 1;
    } while (bVar9);
    if (!bVar9) {
      iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
    }
    if (((iVar3 == 0) && (uVar7 <= param_4)) && (param_4 == uVar7)) {
      if (param_3 == (byte *)0x0) {
        ExceptionList = local_c;
        return local_18;
      }
      bVar1 = param_3[-1];
      if ((bVar1 != 0) && (bVar1 != 0xff)) {
        param_3[-1] = bVar1 - 1;
        ExceptionList = local_c;
        return local_18;
      }
      FUN_004bc150(param_3 + -1);
      ExceptionList = local_c;
      return local_18;
    }
    local_18 = local_18 + 1;
  } while( true );
}

