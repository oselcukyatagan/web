import React from "react";
import {AiFillHome,AiFillFolderOpen} from "react-icons/ai"

export default function Sidebar(){
    return(
        
        <div className="sidebar-placeHolder">

            <p>logo</p>

            <div className="sidebar-content">
                <ul>
                    <li>
                        <a href="/"><AiFillHome size="2rem"/>Home</a>
                    </li>
                    <li>
                        <a href="/"><AiFillFolderOpen size="100px"/>My Collections</a>
                    </li>
                    <li>
                        <a href="/">Favorites</a>
                    </li>
                </ul>
            </div>

            <div className="sidebar-last">
                <button className="sidebar-settings">Settings</button>
                <button className="sidebar-logout">Log Out</button>
            </div>

        </div>
    )
}
