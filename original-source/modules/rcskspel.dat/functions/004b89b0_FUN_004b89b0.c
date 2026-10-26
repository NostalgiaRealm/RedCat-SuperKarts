/*
 * FUN_004b89b0 at 004b89b0
 * undefined FUN_004b89b0(void)
 * Address ranges: 004b89b0-004b8b19
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b89b0(int param_1)

{
  UINT UVar1;
  int iVar2;
  char *pcVar3;
  CHAR local_64 [100];
  
  if (DAT_006ab918 != 0) {
    return 0;
  }
  DAT_006ab8c4 = LocalAlloc(0x40,param_1 * 8);
  if (DAT_006ab8c4 == (HLOCAL)0x0) {
    FUN_004afee0(s__s__d____error_not_enough_memory_005013fc,
                 s_C__libraries_dxdraw_Hwinfo_cpp_0050137c,0x5d);
  }
  iVar2 = 0;
  DAT_006ab8c8 = param_1;
  if (0 < param_1) {
    do {
      FUN_004bea92(local_64,&DAT_005013f4,iVar2 + 0x41);
      *(int *)((int)DAT_006ab8c4 + iVar2 * 8) = iVar2;
      UVar1 = GetDriveTypeA(local_64);
      switch(UVar1) {
      case 0:
        pcVar3 = s__s___UNAVAILABLE_005013e0;
        *(undefined4 *)((int)DAT_006ab8c4 + iVar2 * 8 + 4) = 0;
        break;
      case 1:
        pcVar3 = s__s___UNAVAILABLE_005013e0;
        *(undefined4 *)((int)DAT_006ab8c4 + iVar2 * 8 + 4) = 0;
        break;
      case 2:
        pcVar3 = s__s___FLOPPY_0050139c;
        *(undefined4 *)((int)DAT_006ab8c4 + iVar2 * 8 + 4) = 1;
        break;
      case 3:
        pcVar3 = s__s___HDD_005013b8;
        *(undefined4 *)((int)DAT_006ab8c4 + iVar2 * 8 + 4) = 2;
        break;
      case 4:
        pcVar3 = s__s___NETWORK_005013d0;
        *(undefined4 *)((int)DAT_006ab8c4 + iVar2 * 8 + 4) = 4;
        break;
      case 5:
        pcVar3 = s__s___CDROM_005013c4;
        *(undefined4 *)((int)DAT_006ab8c4 + iVar2 * 8 + 4) = 3;
        break;
      case 6:
        pcVar3 = s__s___RAM_005013ac;
        *(undefined4 *)((int)DAT_006ab8c4 + iVar2 * 8 + 4) = 5;
        break;
      default:
        goto switchD_004b8a3a_default;
      }
      FUN_004afce0(pcVar3,local_64);
switchD_004b8a3a_default:
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1);
  }
  DAT_006ab918 = 1;
  return 0;
}

