﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LoginScene : BaseScene
{
    UI_LoginScene _sceneUI;

    protected override void Init()
    {
        base.Init();

        SceneType = Define.Scene.Login;

        Screen.SetResolution(640, 480, false);

        _sceneUI = Managers.UI.GetSceneUI<UI_LoginScene>();
    }

    public override void Clear()
    {

    }
}
