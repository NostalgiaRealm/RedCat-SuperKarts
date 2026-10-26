/*
 * FUN_00409780 at 00409780
 * undefined4 __cdecl FUN_00409780(LPCSTR param_1, LPCSTR param_2)
 * Address ranges: 00409780-00409ad9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00409780(LPCSTR param_1,LPCSTR param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_24;
  short local_20 [2];
  int local_1c;
  uint local_18 [5];
  
  if (DAT_0043d468 == 0) {
    DAT_0043d454 = (FILE *)FUN_0041f4c6(param_1,&DAT_00430eb8);
    if (DAT_0043d454 == (FILE *)0x0) {
      FUN_0040187a((byte *)s__s__d____could_not_open_<_s>_00430ec8);
      uVar1 = 1000;
    }
    else {
      FUN_0041f3be((char *)local_20,2,1,(int *)DAT_0043d454);
      if (local_20[0] < 1) {
        FUN_0040187a((byte *)s__s__d____could_not_open_<_s>_00430ef4);
        uVar1 = 0x3e9;
      }
      else {
        DAT_0043d45c = (int)local_20[0];
        DAT_0043d460 = LocalAlloc(0x40,DAT_0043d45c * 0x1c);
        if (DAT_0043d460 == (HLOCAL)0x0) {
          FUN_0040187a((byte *)s__s__d____error_not_enough_memory_00430f20);
          uVar1 = 2000;
        }
        else {
          for (local_1c = 0; local_1c < DAT_0043d45c; local_1c = local_1c + 1) {
            FUN_0041f3be((char *)local_18,0x14,1,(int *)DAT_0043d454);
            FUN_0041f3be((char *)&local_24,1,4,(int *)DAT_0043d454);
            FUN_0041f7a0((uint *)((int)DAT_0043d460 + local_1c * 0x1c),local_18);
            *(undefined4 *)((int)DAT_0043d460 + local_1c * 0x1c + 0x14) = local_24;
            if ((DAT_0043d454->_flag & 0x20U) != 0) {
              FUN_0040187a((byte *)s__s__d____error_while_reading_fil_00430f68);
              return 0x3e9;
            }
          }
          FUN_0041f368(DAT_0043d454);
          DAT_0043d458 = FUN_0041f4c6(param_2,&DAT_00430f94);
          if (DAT_0043d458 == 0) {
            FUN_0040187a((byte *)s__s__d____could_not_open_<_s>_00430fa4);
            uVar1 = 1000;
          }
          else {
            uVar2 = FUN_00427d94(DAT_0043d458);
            DAT_0043d450 = FUN_00427d1c(uVar2);
            FUN_004015a6(&DAT_00430fc4);
            FUN_004015a6((byte *)s______s______s_00430fdc);
            FUN_004015a6((byte *)s______s_00431020);
            for (local_1c = 0; local_1c < DAT_0043d45c + -1; local_1c = local_1c + 1) {
              *(int *)((int)DAT_0043d460 + local_1c * 0x1c + 0x18) =
                   *(int *)((int)DAT_0043d460 + (local_1c + 1) * 0x1c + 0x14) -
                   *(int *)((int)DAT_0043d460 + local_1c * 0x1c + 0x14);
              FUN_004015a6((byte *)s______s____d_00431028);
            }
            *(DWORD *)((int)DAT_0043d460 + local_1c * 0x1c + 0x18) =
                 DAT_0043d450 - *(int *)((int)DAT_0043d460 + local_1c * 0x1c + 0x14);
            FUN_004015a6((byte *)s______s____d_00431038);
            FUN_004015a6((byte *)s______s_0043107c);
            DAT_0043d468 = 1;
            uVar1 = 0;
          }
        }
      }
    }
  }
  else {
    FUN_004015a6((byte *)s__s__d____warning___double_call_t_00430e74);
    uVar1 = 0;
  }
  return uVar1;
}

