//
//  ViewController.swift
//  Variables
//
//  Created by Thawee Techathamnukool on 1/28/16.
//  Copyright © 2016 Thawee Techathamnukool. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var label: UILabel! // IB = Interface Builder
    
    var myName:String = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        myName = "Thawee Techathamnukool"
        print(myName)  // output for debugging on output window; not on the app itself
        
        var myVar:String = "Hi"  // var : variable
        let favoriteNum:Int = 5  // let : const
        
        label.text = "My favorite number is \(favoriteNum)"
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

