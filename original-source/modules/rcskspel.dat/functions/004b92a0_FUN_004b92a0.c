/*
 * FUN_004b92a0 at 004b92a0
 * undefined FUN_004b92a0(void)
 * Address ranges: 004b92a0-004b956b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b92a0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int local_1c;
  undefined4 local_18;
  char local_14 [20];
  
  uVar9 = param_1;
  iVar4 = 0;
  if (DAT_006ab944 != 0) {
    FUN_004afce0(s__s__d____warning___double_call_t_005018e4,
                 s_C__libraries_dxdraw_Fileio_cpp_00501928,0x30);
    return 0;
  }
  DAT_006ab930 = FUN_004bf445(param_1,&DAT_005012c0);
  if (DAT_006ab930 == 0) {
    uVar8 = 0x37;
  }
  else {
    FUN_004bf930(&param_1,2,1,DAT_006ab930);
    if ((short)param_1 < 1) {
      FUN_004afee0(s__s__d____could_not_open_<_s>_005018c4,s_C__libraries_dxdraw_Fileio_cpp_00501928
                   ,0x42,uVar9);
      return 0x3e9;
    }
    _DAT_006ab938 = (int)(short)param_1;
    DAT_006ab93c = LocalAlloc(0x40,_DAT_006ab938 * 0x1c);
    if (DAT_006ab93c == (HLOCAL)0x0) {
      FUN_004afee0(s__s__d____error_not_enough_memory_00501888,
                   s_C__libraries_dxdraw_Fileio_cpp_00501928,0x4e);
      return 2000;
    }
    local_1c = 0;
    if (0 < _DAT_006ab938) {
      do {
        FUN_004bf930(local_14,0x14,1,DAT_006ab930);
        FUN_004bf930(&local_18,1,4,DAT_006ab930);
        uVar2 = 0xffffffff;
        pcVar5 = local_14;
        do {
          pcVar7 = pcVar5;
          if (uVar2 == 0) break;
          uVar2 = uVar2 - 1;
          pcVar7 = pcVar5 + 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar7;
        } while (cVar1 != '\0');
        uVar2 = ~uVar2;
        pcVar5 = pcVar7 + -uVar2;
        pcVar7 = (char *)((int)DAT_006ab93c + iVar4);
        for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar7 = pcVar7 + 4;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *pcVar7 = *pcVar5;
          pcVar5 = pcVar5 + 1;
          pcVar7 = pcVar7 + 1;
        }
        *(undefined4 *)((int)DAT_006ab93c + iVar4 + 0x14) = local_18;
        if ((*(byte *)(DAT_006ab930 + 0xc) & 0x20) != 0) {
          FUN_004afee0(s__s__d____error_while_reading_fil_0050185c,
                       s_C__libraries_dxdraw_Fileio_cpp_00501928,0x5d);
          return 0x3e9;
        }
        local_1c = local_1c + 1;
        iVar4 = iVar4 + 0x1c;
      } while (local_1c < _DAT_006ab938);
    }
    FUN_004bf2c5(DAT_006ab930);
    uVar9 = param_2;
    DAT_006ab934 = FUN_004bf445(param_2,&DAT_005012c0);
    if (DAT_006ab934 != 0) {
      uVar8 = FUN_004ccbb9(DAT_006ab934);
      DAT_006ab92c = FUN_004ccb41(uVar8);
      FUN_004afce0(&DAT_00501854,uVar9);
      FUN_004afce0(s______s______s_00501834,0x14,0x14,s_Bestand_00501844,10,10,s_Grootte_0050184c);
      FUN_004afce0(s______s_005017f8,0x21,0x21,s__________________________________00501800);
      iVar4 = 0;
      if (_DAT_006ab938 != 1 && -1 < _DAT_006ab938 + -1) {
        iVar6 = 0;
        do {
          *(int *)(iVar6 + 0x18 + (int)DAT_006ab93c) =
               *(int *)(iVar6 + 0x30 + (int)DAT_006ab93c) -
               *(int *)(iVar6 + 0x14 + (int)DAT_006ab93c);
          FUN_004afce0(s______s____d_005017e8,0x14,0x14,iVar6 + (int)DAT_006ab93c,10,
                       *(undefined4 *)(iVar6 + 0x18 + (int)DAT_006ab93c));
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + 0x1c;
        } while (iVar4 < _DAT_006ab938 + -1);
      }
      iVar4 = iVar4 * 0x1c;
      *(int *)(iVar4 + 0x18 + (int)DAT_006ab93c) =
           DAT_006ab92c - *(int *)(iVar4 + 0x14 + (int)DAT_006ab93c);
      FUN_004afce0(s______s____d_005017e8,0x14,0x14,(HLOCAL)(iVar4 + (int)DAT_006ab93c),10,
                   *(undefined4 *)(iVar4 + (int)DAT_006ab93c + 0x18));
      FUN_004afce0(s______s_005017f8,0x21,0x21,s__________________________________00501800);
      DAT_006ab944 = 1;
      return 0;
    }
    uVar8 = 0x67;
    DAT_006ab934 = 0;
  }
  FUN_004afee0(s__s__d____could_not_open_<_s>_005018c4,s_C__libraries_dxdraw_Fileio_cpp_00501928,
               uVar8,uVar9);
  return 1000;
}

