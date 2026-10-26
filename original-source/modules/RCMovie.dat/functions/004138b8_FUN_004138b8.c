/*
 * FUN_004138b8 at 004138b8
 * undefined4 __cdecl FUN_004138b8(LPCSTR param_1, uint param_2)
 * Address ranges: 004138b8-00413ad1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004138b8(LPCSTR param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *this;
  void *extraout_ECX;
  undefined4 local_3ac;
  undefined4 local_3a8;
  int local_3a4;
  int local_3a0;
  undefined4 local_39c;
  undefined4 local_398;
  undefined4 local_394;
  int local_390;
  FILE *local_38c;
  char local_388 [768];
  int local_88;
  char local_84;
  char local_83;
  short local_7e;
  short local_7a;
  short local_42;
  
  local_38c = (FILE *)FUN_00409d69(param_1);
  if (local_38c == (FILE *)0x0) {
    uVar1 = 1000;
  }
  else {
    if ((param_2 & 2) != 0) {
      FUN_00413622((int *)local_38c,local_388);
    }
    FUN_00409b18((int *)local_38c,0,0);
    FUN_0041f3be(&local_84,0x80,1,(int *)local_38c);
    if ((local_38c->_flag & 0x20U) == 0) {
      this = (void *)(param_2 & 1);
      if (((this != (void *)0x0) && (local_84 == '\n')) && (local_83 == '\x05')) {
        local_88 = ((int)local_7a - (int)local_7e) + 1;
        if (DAT_0042c354 < local_88) {
          local_88 = DAT_0042c354;
        }
        FUN_00414a90(2,&local_38c->_ptr,(int)local_42,local_88);
        this = extraout_ECX;
      }
      if ((param_2 & 6) == 6) {
        FUN_0040e96f(this,DAT_0043d760,0,0x100);
      }
      if ((param_2 & 8) != 0) {
        if ((param_2 & 0x10) == 0) {
          FUN_0040337e();
        }
        else {
          local_3ac = 0;
          local_3a8 = 0;
          local_3a0 = local_88;
          local_3a4 = (int)local_42;
          local_39c = 0;
          local_398 = 0;
          local_390 = DAT_0042c354;
          local_394 = DAT_0042c350;
          iVar2 = (**(code **)(*DAT_00438434 + 0x14))
                            (DAT_00438434,&local_39c,DAT_00438418,&local_3ac,0x1000000,0);
          if (iVar2 != 0) {
            FUN_00401f61(iVar2);
            FUN_0040187a((byte *)s__s__d____blitting_error___s___00434cb4);
          }
        }
      }
      FUN_00409f20(local_38c);
      uVar1 = 0;
    }
    else {
      FUN_0041f368(local_38c);
      uVar1 = 0x3e9;
    }
  }
  return uVar1;
}

